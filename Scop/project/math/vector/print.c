/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:56:38 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:56:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

void				vector2_print(t_vector2 vector)
{
	printf("{%f, %f}\n", vector.x, vector.y);
}

void				vector3_print(t_vector3 vector)
{
	printf("{%f, %f, %f}\n", vector.x, vector.y, vector.z);
}
