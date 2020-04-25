/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:09:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 13:30:42 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*str_uchar;
	unsigned char	c_uchar;
	size_t			i;

	i = 0;
	str_uchar = (unsigned char *)str;
	c_uchar = (unsigned char)c;
	while (i < n)
		str_uchar[i++] = c_uchar;
	return (str);
}
