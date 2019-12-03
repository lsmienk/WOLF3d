/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersection.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 14:24:32 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/04 11:51:49 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		intersection(t_point *pt, t_line *ray, t_point *a, t_point *b)
{
	float	den;
	float	t;
	float	u;

	pt->x = ray->x1;
	pt->y = ray->y1;
	den = (a->x - b->x) * (ray->y1 - ray->y2) -
		(a->y - b->y) * (ray->x1 - ray->x2);
	if (den == 0)
		return ;
	t = (((a->x - ray->x1) * (ray->y1 - ray->y2)) -
		((a->y - ray->y1) * (ray->x1 - ray->x2))) / den;
	u = -(((a->x - b->x) * (a->y - ray->y1)) -
		((a->y - b->y) * (a->x - ray->x1))) / den;
	if (t > 0.0 && t < 1.0 && u > 0.0)
	{
		pt->x = a->x + (t * (b->x - a->x));
		pt->y = a->y + (t * (b->y - a->y));
	}
}
