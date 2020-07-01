/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:55:51 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:55:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_vector2			vector2_empty(void)
{
	return ((t_vector2){0, 0});
}

t_vector3			vector3_empty(void)
{
	return ((t_vector3){0, 0, 0});
}
