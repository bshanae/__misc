/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:56:22 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:56:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_vector3			vector3_normalize(t_vector3 vector)
{
	const float		magnitude = 1.f / vector3_length(vector);

	return (vector3_pack(vector.x * magnitude,
		vector.y * magnitude, vector.z * magnitude));
}
