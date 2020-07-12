/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:53:13 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/12 14:09:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int div;

	if (fd < 0 || fd > 1023)
		return ;
	div = 1000000000;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (ft_abs(n / div) < 1 && div > 1)
		div /= 10;
	while (div >= 1 || (!n && div))
	{
		ft_putchar_fd('0' + ft_abs(n / div), fd);
		n = n % div;
		div /= 10;
	}
}
