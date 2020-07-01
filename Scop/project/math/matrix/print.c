/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:52:57 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:52:58 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

void				matrix_print(const t_matrix *matrix)
{
	int				i;

	i = 0;
	while (i < 4)
	{
		printf("[%f, %f, %f, %f]",
			matrix->data[i][0],
			matrix->data[i][1],
			matrix->data[i][2],
			matrix->data[i][3]);
		i++;
	}
	printf("\n");
}
