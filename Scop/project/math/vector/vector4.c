#include "scop_math.h"

t_vector4			vector4_pack(float x, float y, float z, float w)
{
	return ((t_vector4){x, y, z, w});
}

float 				*vector4_value(t_vector4 *vector, int index)
{
	if (index < 0 || index > 3)
		ft_raise_error(NULL, "Bad vector index");
	return (&vector->x + index);
}

void 				vector4_print(const t_vector4 *vector)
{
	printf("{%f,%f, %f, %f}\n", vector->x, vector->y, vector->z, vector->w);
}