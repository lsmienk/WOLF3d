/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolfloop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:00:29 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/03 17:00:34 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	map(t_mlx *mlx)
{
	bcolour(mlx->im_add, BLACK, BLACK);
	draw_circle(mlx->player.x, mlx->player.y, mlx->im_add);
	twod_draw(mlx, IMRE_PINK);
}

static void	create(t_mlx *mlx)
{
	bcolour(mlx->img_add, BLACK, GREY);
	raycasting(mlx);
}

int			wolfloop(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	map(mlx);
	create(mlx);
	mlx_put_image_to_window(mlx->info, mlx->wi, mlx->im, 0, 0);
	mlx_put_image_to_window(mlx->info, mlx->win, mlx->img, 0, 0);
	return (1);
}
