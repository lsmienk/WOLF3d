/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plotpoint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:01:07 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/03 17:01:10 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		inbounds(int y, int x)
{
	if (x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT)
		return (1);
	return (0);
}

void			plotpoint(int x, int y, int colour, void *img_add)
{
	int *i_img;

	i_img = (int*)img_add;
	if (inbounds(y, x))
		ft_memcpy(&i_img[(y * SCREEN_WIDTH) + x], &colour, 4);
}
