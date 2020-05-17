#include "scop_math.h"

t_vector2			vector2_add(t_vector2 a, t_vector2 b)
{
	return (vector2_pack(a.x + b.x, a.y + b.y));
}

t_vector3			vector3_add(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(a.x + b.x, a.y + b.y, a.z + b.z));
}