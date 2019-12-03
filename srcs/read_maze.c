/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_maze.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 10:38:02 by ihering-       #+#    #+#                */
/*   Updated: 2019/11/27 14:21:18 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		*atoil(char **coord, int w)
{
	int *map;
	int i;

	i = 0;
	map = (int *)ft_memalloc(sizeof(int) * (w + 1));
	if (map == NULL)
		return (NULL);
	while (i < w)
	{
		if (&coord[i][0] == NULL)
			ft_error("Error: Map not Valid");
		map[i] = ft_atoi(&coord[i][0]);
		i++;
	}
	if (&coord[i][0] != NULL)
		ft_error("Error: Map not Valid");
	return (map);
}

static void		free_cords(int fd, t_mlx *mlx)
{
	int		i;
	char	*line;
	char	**coord;

	i = 0;
	mlx->map = (int **)ft_memalloc(sizeof(int *) * (mlx->max_y + 1));
	if (mlx->map == NULL)
		return ;
	while (ft_get_next_line(fd, &line))
	{
		coord = ft_strsplit(line, ' ');
		mlx->map[i] = atoil(coord, mlx->max_x);
		ft_strarrdel(&coord);
		free(line);
		i++;
	}
	close(fd);
}

static int		find_length(char **coord)
{
	int	x;

	x = 0;
	while (coord[x])
		x++;
	return (x);
}

static void		find_height(int fd, t_mlx *mlx)
{
	int		y;
	char	*line;
	char	**coord;

	y = 0;
	while (ft_get_next_line(fd, &line) == 1)
	{
		if (y == 0)
		{
			coord = ft_strsplit(line, ' ');
			mlx->max_x = find_length(coord);
			ft_strarrdel(&coord);
		}
		y++;
		free(line);
	}
	if (!mlx->max_x)
		ft_error("Error: Map is Empty");
	mlx->max_y = y;
	close(fd);
}

void			read_maze(char *av, t_mlx *mlx)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("Error: can't open the file");
	find_height(fd, mlx);
	fd = open(av, O_RDONLY);
	free_cords(fd, mlx);
}
