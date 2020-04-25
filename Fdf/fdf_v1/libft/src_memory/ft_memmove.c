/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:20:15 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/15 11:29:39 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_uchar;
	unsigned char	*src_uchar;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	dest_uchar = (unsigned char *)dest;
	src_uchar = (unsigned char *)src;
	i = 0;
	if (src_uchar < dest_uchar && src_uchar + n > dest_uchar)
		while (i++ < n)
			*(dest_uchar + n - i) = *(src_uchar + n - i);
	else
		while (i++ < n)
			*(dest_uchar++) = *(src_uchar++);
	return (dest);
}
