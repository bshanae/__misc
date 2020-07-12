/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:55:25 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:55:26 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

float				*vector3_array(t_vector3 *vector, int index)
{
	if (index < 0 || index > 3)
		ft_raise_error(NULL, "Bad vector index");
	return (&vector->x + index);
}
