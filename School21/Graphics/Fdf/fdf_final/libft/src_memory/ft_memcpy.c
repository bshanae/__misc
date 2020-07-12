/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:09:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/15 11:29:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_uchar;
	unsigned char *src_uchar;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	dest_uchar = (unsigned char *)dest;
	src_uchar = (unsigned char *)src;
	while (n-- > 0)
		*(dest_uchar++) = *(src_uchar++);
	return (dest);
}
