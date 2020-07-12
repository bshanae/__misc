/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:55:58 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:55:59 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

float				vector3_length_squared(t_vector3 vector)
{
	return (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

float				vector3_length(t_vector3 vector)
{
	return (sqrtf(vector3_length_squared(vector)));
}