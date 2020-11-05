/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbo_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:51:44 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:51:45 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_vbo				vbo_create(void)
{
	t_vbo			vbo;

	glGenBuffers(1, &vbo);
	return (vbo);
}

void				vbo_destroy(t_vbo *vbo)
{
	glDeleteBuffers(1, vbo);
}

void				vbo_bind(const t_vbo *vbo)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo ? *vbo : 0);
}

void				vbo_buffer(const t_vector *vector)
{
	glBufferData(GL_ARRAY_BUFFER, vector->length * vector->element_size,
		vector->storage, GL_STATIC_DRAW);
}
