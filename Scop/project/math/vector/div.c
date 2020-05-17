#include "scop_math.h"

t_vector2			vector2_div(t_vector2 vector, float value)
{
	return (vector2_mul(vector, 1.f / value));
}

t_vector3			vector3_div(t_vector3 vector, float value)
{
	return (vector3_mul(vector, 1.f / value));
}
