/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 17:14:03 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/27 13:59:49 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
