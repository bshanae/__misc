/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:56:08 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:56:10 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_vector3			vector3_min(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z)));
}
