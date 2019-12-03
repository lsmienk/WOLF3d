/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_controls.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 13:06:37 by ihering-       #+#    #+#                */
/*   Updated: 2019/11/12 15:33:44 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		move_foward(t_mlx *mlx)
{
	t_point	add;
	t_point	new;

	add.x = cos(mlx->angle * MPI) * 5;
	add.y = sin(mlx->angle * MPI) * 5;
	new.x = mlx->player.x + add.x;
	new.y = mlx->player.y + add.y;
	if (collision(mlx, &new))
		return ;
	mlx->player.y = new.y;
	mlx->player.x = new.x;
}

static void		move_backwards(t_mlx *mlx)
{
	t_point	add;
	t_point	new;

	add.x = cos(mlx->angle * MPI) * 5;
	add.y = sin(mlx->angle * MPI) * 5;
	new.x = mlx->player.x - add.x;
	new.y = mlx->player.y - add.y;
	if (collision(mlx, &new))
		return ;
	mlx->player.y = new.y;
	mlx->player.x = new.x;
}

static int		keycontrol(int key, void *param, t_mlx *mlx)
{
	mlx = (t_mlx*)param;
	if (key == KEY_ESC)
		closeprogram(param);
	else if (key == KEY_LEFT)
	{
		mlx->angle -= 5;
		if (mlx->angle == 0)
			mlx->angle = 360 + mlx->angle;
	}
	else if (key == KEY_RIGHT)
	{
		mlx->angle += 5;
		if (mlx->angle == 360)
			mlx->angle = mlx->angle - 360;
	}
	else if (key == KEY_UP)
		move_foward(mlx);
	else if (key == KEY_DOWN)
		move_backwards(mlx);
	return (1);
}

void			controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, KEY_PRESS_EVENT, NULL_MASK, keycontrol, (void*)mlx);
	mlx_hook(mlx->win, CLOSE_EVENT, NULL_MASK, closeprogram, NULL);
}
