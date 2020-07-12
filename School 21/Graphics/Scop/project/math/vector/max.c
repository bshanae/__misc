/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:56:03 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:56:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_vector3			vector3_max(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z)));
}
