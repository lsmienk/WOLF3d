/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_distance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 15:17:59 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/04 11:39:36 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		line_distance(t_point a, t_point b)
{
	float		dis;
	double		c;
	double		d;

	c = fabs(a.x - b.x);
	d = fabs(a.y - b.y);
	dis = pow(c, 2) + pow(d, 2);
	dis = sqrt(dis);
	return (dis);
}
