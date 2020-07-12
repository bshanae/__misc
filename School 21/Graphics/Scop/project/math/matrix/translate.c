/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:53:47 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:53:48 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix			matrix_translate(t_vector3 value)
{
	t_matrix		matrix;
	int				i;

	matrix = matrix_identity();
	i = 0;
	while (i < 3)
	{
		matrix.data[3][i] = *vector3_array(&value, i);
		i++;
	}
	return (matrix);
}
