/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:09:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 16:55:55 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int value, size_t n)
{
	unsigned char *dest_uchar;
	unsigned char *src_uchar;
	unsigned char value_uchar;

	dest_uchar = (unsigned char *)dest;
	src_uchar = (unsigned char *)src;
	value_uchar = (unsigned char)value;
	while (n-- > 0)
	{
		*(dest_uchar++) = *(src_uchar++);
		if (*(src_uchar - 1) == value_uchar)
			return ((void *)dest_uchar);
	}
	return (NULL);
}
