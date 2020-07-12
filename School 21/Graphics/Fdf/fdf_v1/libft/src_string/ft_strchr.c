/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:31:13 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 15:39:15 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int value)
{
	char value_ch;

	value_ch = (char)value;
	while (1)
	{
		if (*(str) == value_ch)
			return ((char *)str);
		if (!*str)
			break ;
		str++;
	}
	return (NULL);
}
