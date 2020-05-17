#include "scop_math.h"

t_vector3			vector3_normalize(t_vector3 vector)
{
	const float 	magnitude = 1.f / vector3_length(vector);

	return (vector3_pack(vector.x * magnitude, vector.y * magnitude, vector.z * magnitude));
}