/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_wall.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:18:12 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/14 10:30:04 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		render_wall(t_mlx *mlx, float he, float i, t_wall *c)
{
	int		w;
	t_point	pos;
	float	ystart;
	float	h;

	w = ((i - (mlx->angle - (FOV / 2))) * (SCREEN_WIDTH / FOV));
	pos.y = (SCREEN_HEIGHT / 2) - (he / 2);
	ystart = pos.y;
	h = (SCREEN_HEIGHT / 2) + (he / 2);
	while (pos.y <= h)
	{
		pos.x = w;
		while (pos.x <= (w + 1))
		{
			c->th = (1 - ((h - pos.y) / (he)));
			calc_pix(mlx, c, &mlx->tex[c->wall], pos);
			pos.x++;
		}
		pos.y++;
	}
}
