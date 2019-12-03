/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:00:59 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/03 17:01:02 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			is_closer(t_mlx *mlx, t_wall *pt, t_wall *close, t_wall *a)
{
	t_point play;
	float	x;

	play.x = mlx->player.x;
	play.y = mlx->player.y;
	pt->pos.z = line_distance(pt->pos, play);
	if (pt->pos.z < close->pos.z && (pt->pos.x != mlx->player.x))
	{
		close->pos.z = pt->pos.z;
		close->pos.x = pt->pos.x;
		close->pos.y = pt->pos.y;
		x = line_distance(a->pos, close->pos);
		close->tw = (WALLW - x) / WALLW;
		return (1);
	}
	return (0);
}

static void			close_z(t_mlx *mlx, t_wall close, float angle)
{
	float	h;

	h = calc_wall(mlx, &close, angle);
	if (close.pos.z < 214364747)
	{
		render_wall(mlx, h, angle, &close);
		draw_line(mlx->player, close.pos, mlx->im_add, WHITE);
	}
}

static void			cast_rays(t_mlx *mlx, t_line *ray, float angle)
{
	t_maze	*wall;
	t_list	*list;
	t_wall	pt;
	t_wall	close;

	close.pos.z = 214364747;
	list = mlx->maze;
	while (list != NULL)
	{
		wall = list->content;
		intersection(&pt.pos, ray, &wall->point[0].pos, &wall->point[1].pos);
		if (is_closer(mlx, &pt, &close, &wall->point[1]) == 1)
			close.wall = 0;
		intersection(&pt.pos, ray, &wall->point[1].pos, &wall->point[2].pos);
		if (is_closer(mlx, &pt, &close, &wall->point[2]) == 1)
			close.wall = 3;
		intersection(&pt.pos, ray, &wall->point[2].pos, &wall->point[3].pos);
		if (is_closer(mlx, &pt, &close, &wall->point[3]) == 1)
			close.wall = 2;
		intersection(&pt.pos, ray, &wall->point[3].pos, &wall->point[0].pos);
		if (is_closer(mlx, &pt, &close, &wall->point[0]) == 1)
			close.wall = 1;
		list = list->next;
	}
	close_z(mlx, close, angle);
}

void				raycasting(t_mlx *mlx)
{
	t_line	ray;
	float	a;
	float	max;

	ray.x1 = mlx->player.x;
	ray.y1 = mlx->player.y;
	a = mlx->angle - (FOV / 2);
	max = mlx->angle + (FOV / 2);
	while (a < max)
	{
		ray.x2 = ray.x1 + cos(a * MPI);
		ray.y2 = ray.y1 + sin(a * MPI);
		cast_rays(mlx, &ray, a);
		a += 0.05;
	}
}
