/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:52:37 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:52:38 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix			matrix_identity(void)
{
	t_matrix		matrix;
	int				i;

	matrix = matrix_empty();
	i = 0;
	while (i < 4)
	{
		matrix.data[i][i] = 1.f;
		i++;
	}
	return (matrix);
}
