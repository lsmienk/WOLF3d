/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   d_draw.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:01:36 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/03 17:01:38 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		twod_draw(t_mlx *mlx, int colour)
{
	t_maze	*wall;
	t_list	*lst;

	lst = mlx->maze;
	while (lst != NULL)
	{
		wall = lst->content;
		if (lst->content == NULL)
			ft_error("Error: Invalid Map");
		draw_line(wall->point[0].pos, wall->point[1].pos, mlx->im_add, colour);
		draw_line(wall->point[1].pos, wall->point[2].pos, mlx->im_add, colour);
		draw_line(wall->point[2].pos, wall->point[3].pos, mlx->im_add, colour);
		draw_line(wall->point[3].pos, wall->point[0].pos, mlx->im_add, colour);
		lst = lst->next;
	}
}
