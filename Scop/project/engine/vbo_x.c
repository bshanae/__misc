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
