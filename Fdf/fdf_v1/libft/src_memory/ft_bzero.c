/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:54:12 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 14:02:13 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*str_uchar;
	size_t			i;

	str_uchar = (unsigned char *)str;
	i = 0;
	while (i < n)
		str_uchar[i++] = 0;
}
