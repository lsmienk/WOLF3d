/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_circle.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 13:24:07 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/05 13:25:57 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			draw_circle(int x, int y, void *img_add)
{
	int r;
	int i;
	int j;

	r = 10;
	i = x - r;
	while (i < x + r && x > 0 && i < SCREEN_WIDTH)
	{
		j = y - r;
		while (j < y + r && y > 0 && j < SCREEN_HEIGHT)
		{
			if (i > 0 && j > 0 && sqrt(pow(i - x, 2) + pow(j - y, 2)) < r)
				plotpoint(i, j, WHITE, img_add);
			j++;
		}
		i++;
	}
}
