/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_walls.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:01:44 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/03 17:01:47 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		cal_points(t_maze *walls, int x, int y)
{
	walls->point[0].pos.x = x * WALLW;
	walls->point[0].pos.y = y * WALLW;
	walls->point[1].pos.x = walls->point[0].pos.x + WALLW;
	walls->point[1].pos.y = walls->point[0].pos.y;
	walls->point[2].pos.x = walls->point[0].pos.x + WALLW;
	walls->point[2].pos.y = walls->point[0].pos.y + WALLW;
	walls->point[3].pos.x = walls->point[0].pos.x;
	walls->point[3].pos.y = walls->point[0].pos.y + WALLW;
}

void		create_walls(t_mlx *mlx, t_list *lst)
{
	t_point	pos;

	mlx->maze = ft_lstnew(NULL, sizeof(t_maze));
	pos.y = 0;
	while (pos.y < mlx->max_y)
	{
		pos.x = 0;
		while (pos.x < mlx->max_x)
		{
			if (mlx->map[(int)pos.y][(int)pos.x] == 1)
			{
				if (lst == NULL)
					lst = mlx->maze;
				else
				{
					lst->next = ft_lstnew(NULL, sizeof(t_maze));
					lst = lst->next;
				}
				lst->content = (t_maze*)(ft_memalloc(sizeof(t_maze)));
				cal_points(lst->content, pos.x, pos.y);
			}
			pos.x++;
		}
		pos.y++;
	}
}
