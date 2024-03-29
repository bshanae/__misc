/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:48:06 by bshanae           #+#    #+#             */
/*   Updated: 2019/02/11 16:34:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	put_char(char c)
{
	write(1, &c, 1);	
}

void	set(int *arr)
{
	int i;

	i = 0;
	while (i < 11)
	{
		arr[i] = 0;
		i++;
	}
}

void	print(int *arr)
{
	int i;
	int null_flag;

	null_flag = 0;
	i = 9;
	if (arr[10] == 1)
		put_char('-');
	while (i >= 0)
	{
		if ((arr[i] != 0 || null_flag != 0) || i == 0)
		{
			null_flag = 1;
			put_char(arr[i] + '0');
		}
		i--;
	}
}

void	tokenize(int nb, int *dest_arr)
{
	int i;

	i = 0;
	if (nb == -2147483648)
	{
		nb /= 10;
		dest_arr[0] = 8;
		i = 1;
	}
	if (nb < 0)
	{
		dest_arr[10] = 1;
		nb *= -1;
	}
	while (nb >= 1 && i < 11)
	{
		dest_arr[i] = nb % 10;
		nb /= 10;
		i++;
	}
}

void	put_num(int nb)
{
	int arr[11];

	set(arr);
	tokenize(nb, arr);
	print(arr);
}
