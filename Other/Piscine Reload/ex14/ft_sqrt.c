/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:29:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/03 17:33:35 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int x;

	x = 1;
	while (x * x < nb)
		x++;
	return ((x * x == nb) ? (x) : (0));
}