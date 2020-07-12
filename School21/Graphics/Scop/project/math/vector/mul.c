/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:56:14 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:56:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_vector2			vector2_mul(t_vector2 vector, float value)
{
	return (vector2_pack(vector.x * value, vector.y * value));
}

t_vector3			vector3_mul(t_vector3 vector, float value)
{
	return (vector3_pack(vector.x * value, vector.y * value, vector.z * value));
}
