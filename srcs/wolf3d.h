/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:00:39 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/03 17:00:41 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include "values.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct	s_tex
{
	void		*img;
	void		*img_add;
}				t_tex;

typedef struct	s_wall
{
	t_point		pos;
	float		tw;
	float		th;
	int			wall;
}				t_wall;

typedef	struct	s_line
{
	float			y1;
	float			x1;
	float			y2;
	float			x2;
}				t_line;

typedef struct	s_maze
{
	t_wall		point[4];
}				t_maze;

typedef struct	s_mlx
{
	void		*info;
	void		*win;
	void		*wi;
	void		*mlx;
	void		*img;
	void		*im;
	void		*im_add;
	void		*img_add;
	t_tex		tex[4];
	float		pdis;
	int			max_y;
	int			max_x;
	int			**map;
	float		angle;
	t_point		player;
	t_maze		*wall;
	t_list		*maze;
}				t_mlx;

int				main(int argc, char **argv);
void			read_maze(char *av, t_mlx *mlx);
void			create_walls(t_mlx *mlx, t_list *lst);
int				wolfloop(void *param);
void			twod_draw(t_mlx *mlx, int colour);
void			draw_circle(int x, int y, void *img_add);
void			plotpoint(int x, int y, int colour, void *img_add);
void			draw_line(t_point pointa, t_point pointb, void *img_add,
				int col);
void			controls(t_mlx *mlx);
void			raycasting(t_mlx *mlx);
void			intersection(t_point *pt, t_line *ray, t_point *a, t_point *b);
float			line_distance(t_point a, t_point b);
void			bcolour(void *img_add, int c, int cc);
float			calc_wall(t_mlx *mlx, t_wall *wall, float i);
void			render_wall(t_mlx *mlx, float he, float i, t_wall *c);
void			calc_pix(t_mlx *mlx, t_wall *close, t_tex *tex, t_point pos);
int				collision(t_mlx *mlx, t_point *next);

#endif
