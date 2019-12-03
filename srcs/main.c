/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:01:15 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/03 17:01:17 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	set_texture(t_mlx *mlx, int tmp)
{
	int height;
	int width;

	height = 600;
	width = 600;
	mlx->tex[0].img = mlx_xpm_file_to_image(mlx->info, \
						"xpm/black.xpm", &height, &width);
	mlx->tex[0].img_add = mlx_get_data_addr(mlx->tex[0].img, &tmp, &tmp, &tmp);
	mlx->tex[1].img = mlx_xpm_file_to_image(mlx->info, \
											"xpm/tile.xpm", &height, &width);
	mlx->tex[1].img_add = mlx_get_data_addr(mlx->tex[1].img, &tmp, &tmp, &tmp);
	mlx->tex[2].img = mlx_xpm_file_to_image(mlx->info, \
											"xpm/gold.xpm", &height, &width);
	mlx->tex[2].img_add = mlx_get_data_addr(mlx->tex[2].img, &tmp, &tmp, &tmp);
	mlx->tex[3].img = mlx_xpm_file_to_image(mlx->info, \
											"xpm/shampoo.xpm", &height, &width);
	mlx->tex[3].img_add = mlx_get_data_addr(mlx->tex[3].img, &tmp, &tmp, &tmp);
}

static void	setup(t_mlx *mlx)
{
	int tmp;

	tmp = 0;
	mlx->info = mlx_init();
	mlx->wi = mlx_new_window(mlx->info, SCREEN_WIDTH, SCREEN_HEIGHT, "map");
	mlx->im = mlx_new_image(mlx->info, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->im_add = mlx_get_data_addr(mlx->im, &tmp, &tmp, &tmp);
	mlx->win = mlx_new_window(mlx->info, SCREEN_WIDTH, SCREEN_HEIGHT, "WOLF");
	mlx->img = mlx_new_image(mlx->info, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img_add = mlx_get_data_addr(mlx->img, &tmp, &tmp, &tmp);
	set_texture(mlx, tmp);
	mlx->player.x = 30;
	mlx->player.y = 30;
	mlx->angle = 100;
	controls(mlx);
	mlx_loop_hook(mlx->info, wolfloop, (void*)mlx);
}

int			main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_list	*lst;

	lst = NULL;
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	if (!mlx)
		ft_error("Error: malloc failed");
	if (argc >= 1)
	{
		read_maze(argv[1], mlx);
		create_walls(mlx, lst);
		setup(mlx);
		mlx_loop(mlx->info);
	}
	return (0);
}
