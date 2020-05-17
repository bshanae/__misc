#include "scop_math.h"

t_vector3			vector3_cross(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(
		a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
}