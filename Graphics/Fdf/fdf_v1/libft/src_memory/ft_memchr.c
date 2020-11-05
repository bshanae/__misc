/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:13:46 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 13:22:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int value, size_t n)
{
	unsigned char	*str_uchar;
	unsigned char	value_uchar;
	size_t			i;

	str_uchar = (unsigned char*)str;
	value_uchar = (unsigned char)value;
	i = 0;
	while (i++ < n)
		if (*(str_uchar++) == value_uchar)
			return ((void *)(str_uchar - 1));
	return (NULL);
}
