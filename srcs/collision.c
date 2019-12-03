/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 14:57:09 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/27 14:12:49 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_intersect(t_mlx *mlx, t_point *next, t_point *a, t_point *b)
{
	float	den;
	float	t;
	float	u;

	den = (a->x - b->x) * (mlx->player.y - next->y) -
		(a->y - b->y) * (mlx->player.x - next->x);
	if (den == 0)
		return (0);
	t = (((a->x - mlx->player.x) * (mlx->player.y - next->y)) -
		((a->y - mlx->player.y) * (mlx->player.x - next->x))) / den;
	u = -(((a->x - b->x) * (a->y - mlx->player.y)) -
		((a->y - b->y) * (a->x - mlx->player.x))) / den;
	if (t > 0.0 && t < 1.0 && u > 0.0 && u < 5.0)
		return (1);
	return (0);
}

int			collision(t_mlx *mlx, t_point *next)
{
	t_maze	*wall;
	t_list	*lst;

	lst = mlx->maze;
	while (lst != NULL)
	{
		wall = lst->content;
		if (check_intersect(mlx, next, &wall->point[0].pos, \
							&wall->point[1].pos))
			return (1);
		else if (check_intersect(mlx, next, &wall->point[1].pos, \
									&wall->point[2].pos))
			return (1);
		else if (check_intersect(mlx, next, &wall->point[2].pos, \
								&wall->point[3].pos))
			return (1);
		else if (check_intersect(mlx, next, &wall->point[0].pos, \
									&wall->point[3].pos))
			return (1);
		lst = lst->next;
	}
	return (0);
}
