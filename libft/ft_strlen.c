/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 09:48:01 by lsmienk        #+#    #+#                */
/*   Updated: 2019/11/27 14:02:42 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
