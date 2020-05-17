#include "engine.h"

static void			helper(t_mesh *mesh, int i)
{
	t_vector3		*ptr;
	t_vector3		u;
	t_vector3		v;
	t_vector3		n;

	ptr = vector_at(mesh->vector_vertex, i + 0);
	u = vector3_sub(ptr[1], ptr[0]);
	v = vector3_sub(ptr[2], ptr[0]);
	n = vector3_cross(u, v);
	n = vector3_normalize(n);
	ptr = vector_at(mesh->vector_normal, i + 0);
	ptr[0] = n;
	ptr[1] = n;
	ptr[2] = n;
}

void				model_auto_normal(t_engine *engine)
{
	int				i_mesh;
	int				i_vertex;
	t_mesh			*mesh;

	i_mesh = 0;
	while (i_mesh < (int)engine->model.meshes->length)
	{
		mesh = vector_at(engine->model.meshes, i_mesh++);
		i_vertex = 0;
		while (i_vertex < (int)mesh->vector_vertex->length)
		{
			helper(mesh, i_vertex);
			i_vertex += 3;
		}
	}
}

void				model_auto_texture(t_engine *engine)
{
	int				i_mesh;
	int				i_vertex;
	t_mesh			*mesh;
	t_vector3		*vertex;
	t_vector2		*texture;

	i_mesh = 0;
	while (i_mesh < (int)engine->model.meshes->length)
	{
		mesh = vector_at(engine->model.meshes, i_mesh++);
		i_vertex = 0;
		while (i_vertex < (int)mesh->vector_vertex->length)
		{
			vertex = vector_at(mesh->vector_vertex, i_vertex);
			texture = vector_at(mesh->vector_texture, i_vertex);
			i_vertex++;
			texture->x = vertex->z * 2.f;
			texture->y = vertex->y * 2.f;
		}
	}
}

void				model_auto_scale(t_engine *engine)
{
	t_vector3		scale;

	scale.x = SCOP_MODEL_LIMIT.x / engine->model.size.x;
	scale.y = SCOP_MODEL_LIMIT.y / engine->model.size.y;
	scale.z = SCOP_MODEL_LIMIT.z / engine->model.size.z;
	engine->model.scale = fminf(scale.x, scale.y);
	engine->model.scale = fminf(engine->model.scale, scale.z);
	model_update(engine, NULL);
}
