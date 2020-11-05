/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:16:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/07 21:22:05 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	if (!(res_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		res_str[i] = f(i, s[i]);
		i++;
	}
	res_str[i] = '\0';
	return (res_str);
}
