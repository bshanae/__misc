/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:09:19 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/14 14:14:10 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res_str;
	int		res_i;

	if (!s || !f)
		return (NULL);
	if (!(res_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	res_i = 0;
	while (*s)
		res_str[res_i++] = f(*(s++));
	return (res_str);
}
