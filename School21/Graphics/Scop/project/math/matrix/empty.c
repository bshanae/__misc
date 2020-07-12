/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:52:30 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:52:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix			matrix_empty(void)
{
	t_matrix		matrix;
	const float		row[4] = {0, 0, 0, 0};
	int				i;

	i = 0;
	while (i < 4)
		ft_memcpy(matrix.data[i++], row, sizeof(float) * 4);
	return (matrix);
}
