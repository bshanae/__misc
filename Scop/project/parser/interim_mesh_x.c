#include "parser.h"

t_interim_mesh		interim_mesh_create(void)
{
	t_interim_mesh	mesh;

	mesh.data = vector_create(sizeof(t_interim_vertex));
	mesh.material = NULL;
	return (mesh);
}

void				interim_mesh_destroy(t_interim_mesh *mesh)
{
	vector_destroy(&mesh->data);
}
