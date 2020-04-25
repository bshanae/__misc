/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:16:27 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/17 15:41:39 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*str1_uchar;
	unsigned char	*str2_uchar;
	size_t			i;

	str1_uchar = (unsigned char*)str1;
	str2_uchar = (unsigned char*)str2;
	i = 0;
	while (i++ < n)
		if (*(str1_uchar++) != *(str2_uchar++))
			return (*(str1_uchar - 1) - *(str2_uchar - 1));
	return (0);
}
