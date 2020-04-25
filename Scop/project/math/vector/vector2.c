#include "scop_math.h"

t_vector2			vector2_empty()
{
	return ((t_vector2){0, 0});
}

t_vector2			vector2_pack(float x, float y)
{
	return ((t_vector2){x, y});
}

t_vector2			vector2_add(t_vector2 a, t_vector2 b)
{
	return (vector2_pack(a.x + b.x, a.y + b.y));
}

t_vector2			vector2_sub(t_vector2 a, t_vector2 b)
{
	return (vector2_pack(a.x - b.x, a.y - b.y));
}

t_vector2			vector2_mul(t_vector2 vector, float value)
{
	return (vector2_pack(vector.x * value, vector.y * value));
}

t_vector2			vector2_div(t_vector2 vector, float value)
{
	return (vector2_mul(vector, 1.f / value));
}

void 				vector2_print(t_vector2 vector)
{
	printf("{%f, %f}\n", vector.x, vector.y);
}