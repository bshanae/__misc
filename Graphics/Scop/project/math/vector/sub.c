/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:56:54 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:56:55 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_vector2			vector2_sub(t_vector2 a, t_vector2 b)
{
	return (vector2_pack(a.x - b.x, a.y - b.y));
}

t_vector3			vector3_sub(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(a.x - b.x, a.y - b.y, a.z - b.z));
}
