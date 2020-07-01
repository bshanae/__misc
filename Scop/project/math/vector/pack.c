/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:56:32 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:56:34 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_vector2			vector2_pack(float x, float y)
{
	return ((t_vector2){x, y});
}

t_vector3			vector3_pack(float x, float y, float z)
{
	return ((t_vector3){x, y, z});
}
