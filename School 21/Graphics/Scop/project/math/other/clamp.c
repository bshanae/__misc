/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:53:57 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:53:58 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

float				clamp(float min, float max, float value)
{
	if (value > max)
		return (max);
	if (value < min)
		return (min);
	return (value);
}
