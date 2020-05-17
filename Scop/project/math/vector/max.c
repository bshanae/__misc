#include "scop_math.h"

t_vector3 			vector3_max(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z)));
}