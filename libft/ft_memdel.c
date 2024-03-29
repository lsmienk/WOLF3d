/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 10:40:37 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/27 14:02:42 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
