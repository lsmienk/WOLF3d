/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_pix.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:30:14 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/26 13:20:18 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc_pix(t_mlx *mlx, t_wall *close, t_tex *tex, t_point pos)
{
	int c;
	int y;
	int x;

	y = 600 * close->th;
	x = 600 * close->tw;
	c = (y * 600) + x;
	if (c > (600 * 600) || c < 0)
		c = (0);
	plotpoint((int)pos.x, (int)pos.y, ((int*)(tex->img_add))[c], mlx->img_add);
}
