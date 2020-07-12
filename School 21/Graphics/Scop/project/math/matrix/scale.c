/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:53:22 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:53:24 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix			matrix_scale(float value)
{
	t_matrix		matrix;
	int				i;

	matrix = matrix_identity();
	i = 0;
	while (i < 3)
	{
		matrix.data[i][i] = value;
		i++;
	}
	return (matrix);
}
