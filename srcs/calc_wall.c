/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:47:25 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/27 14:27:07 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		projection_distance(t_mlx *mlx, float dis1, float i)
{
	float dis;

	dis = dis1 * cosf((i - (mlx->angle - (FOV / 2))) * (PI / 180));
	mlx->pdis = dis;
}

float			calc_wall(t_mlx *mlx, t_wall *wall, float i)
{
	float ldis;
	float height;

	ldis = wall->pos.z;
	if (ldis == 0)
		ldis = 1;
	projection_distance(mlx, ldis, i);
	if (mlx->pdis > WALLH)
		mlx->pdis = WALLH;
	height = (WALLW / mlx->pdis);
	height *= WALLH;
	return ((int)height);
}
