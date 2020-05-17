#include "scop_math.h"

t_vector3			vector3_min(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z)));
}
