/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bcolour.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 14:12:09 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/05 13:54:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	bcolour(void *img_add, int c, int cc)
{
	int x;
	int y;
	int h;

	y = 0;
	h = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y >= h)
				plotpoint(x, y, c, img_add);
			else
				plotpoint(x, y, cc, img_add);
			x++;
		}
		y++;
	}
}
