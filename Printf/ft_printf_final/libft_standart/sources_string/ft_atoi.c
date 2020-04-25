/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:55:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/09 20:16:24 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ');
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int			ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	x;

	sign = 1;
	x = 0;
	while (is_space(*str))
		str++;
	if ((*str == '-' || *str == '+') && is_digit(*(str + 1)))
		sign = (*(str++) == '-') ? (-1) : (1);
	while (is_digit(*str))
	{
		x = (x * 10) + (*(str++) - '0');
		if ((x >= 1000000000000000000 && *str && sign == 1) ||
			(x >= 9223372036854775807 && sign == 1))
			return (-1);
		else if ((x >= 1000000000000000000 && *str && sign == -1) ||
			(x > 9223372036854775807 && sign == -1))
			return (0);
	}
	return ((int)(x * sign));
}
