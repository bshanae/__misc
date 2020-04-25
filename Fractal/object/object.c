/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:09:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 14:49:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_object				*object_new(void)
{
	t_object			*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		exit(21);
	new->iter = 0;
	*(t_vector3 *)&new->unit = UNIT3;
	new->free = object_init_free();
	new->cube = object_init_cube();
	new->r_sphere = object_init_r_sphere();
	new->tetrahedron = object_init_tetrahedron();
	new->mandelbrot = object_init_mandelbrot();
	new->mandelbulb = object_init_mandelbulb();
	new->julia = object_init_julia();
	return (new);
}

void					object_delete(t_object **obj)
{
	free(*obj);
	*obj = NULL;
}
