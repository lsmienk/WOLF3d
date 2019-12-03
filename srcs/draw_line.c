/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:01:27 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/03 17:01:29 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	steepy(t_point *pos1, t_point *pos2, void *img_add, int colour)
{
	int x;
	int y;
	int dx;
	int dy;

	dx = pos2->x - pos1->x;
	dy = pos2->y - pos1->y;
	y = pos1->y;
	while (y < pos2->y)
	{
		x = pos1->x + dx * (y - pos1->y) / dy;
		plotpoint(x, y, colour, img_add);
		y++;
	}
}

static void	steepx(t_point *pos1, t_point *pos2, void *img_add, int colour)
{
	int x;
	int y;
	int dx;
	int dy;

	dx = pos2->x - pos1->x;
	dy = pos2->y - pos1->y;
	x = pos1->x;
	while (x < pos2->x)
	{
		y = pos1->y + dy * (x - pos1->x) / dx;
		plotpoint(x, y, colour, img_add);
		x++;
	}
}

void		draw_line(t_point pointa, t_point pointb, void *img_add, int col)
{
	if (fabs(pointb.x - pointa.x) > fabs(pointb.y - pointa.y))
	{
		if (pointa.x > pointb.x)
			steepx(&pointb, &pointa, img_add, col);
		else
			steepx(&pointa, &pointb, img_add, col);
	}
	else
	{
		if (pointa.y > pointb.y)
			steepy(&pointb, &pointa, img_add, col);
		else
			steepy(&pointa, &pointb, img_add, col);
	}
}
