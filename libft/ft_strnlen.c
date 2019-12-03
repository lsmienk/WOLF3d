/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 13:37:00 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/27 14:02:42 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnlen(char *str, int i, char c)
{
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}
