/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:53:33 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:53:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "some_math.h"

double		ft_ipart(double x)
{
	return (floor(x));
}

double		ft_fpart(double x)
{
	return (x - floor(x));
}

double		ft_rfpart(double x)
{
	return (1 - ft_fpart(x));
}

void		swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
