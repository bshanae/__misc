#include "scop_math.h"

t_vector3			vector3_empty()
{
	return ((t_vector3){0, 0 , 0});
}

t_vector3			vector3_pack(float x, float y, float z)
{
	return ((t_vector3){x, y, z});
}

float 				*vector3_value(t_vector3 *vector, int index)
{
	if (index < 0 || index > 3)
		ft_raise_error(NULL, "Bad vector index");
	return (&vector->x + index);
}

void 				vector3_print(t_vector3 vector)
{
	printf("{%f, %f, %f}\n", vector.x, vector.y, vector.z);
}

t_vector3			vector3_add(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vector3			vector3_sub(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vector3			vector3_mul(t_vector3 vector, float value)
{
	return (vector3_pack(vector.x * value, vector.y * value, vector.z * value));
}

t_vector3			vector3_div(t_vector3 vector, float value)
{
	return (vector3_mul(vector, 1.f / value));
}

float				vector3_dot(t_vector3 a, t_vector3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector3			vector3_cross(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(
		a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
}

float 				vector3_length_squared(t_vector3 vector)
{
	return (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

float 				vector3_length(t_vector3 vector)
{
	return (sqrtf(vector3_length_squared(vector)));
}

t_vector3			vector3_normalize(t_vector3 vector)
{
	const float 	magnitude = 1.f / vector3_length(vector);

	return (vector3_pack(vector.x * magnitude, vector.y * magnitude, vector.z * magnitude));
}

static void			helper_rotate_x(t_vector3 *vector, float angle)
{
	t_vector3		copy;

	copy = *vector;
	vector->y = copy.y * cosf(angle) + copy.z * sinf(angle);
	vector->z = -1 * copy.y * sinf(angle) + copy.z * cosf(angle);
}

static void			helper_rotate_y(t_vector3 *vector, float angle)
{
	t_vector3		copy;

	copy = *vector;
	vector->x = copy.x * cosf(angle) + copy.z * sinf(angle);
	vector->z = -1 * copy.x * sinf(angle) + copy.z * cosf(angle);
}

static void			helper_rotate_z(t_vector3 *vector, float angle)
{
	t_vector3		copy;

	copy = *vector;
	vector->x = copy.x * cosf(angle) - copy.y * sinf(angle);
	vector->y = copy.x * sinf(angle) + copy.y * cosf(angle);
}

t_vector3			vector3_rotate(t_vector3 vector, t_axis axis, float angle)
{
	if (axis == axis_x)
		helper_rotate_x(&vector, angle);
	else if (axis == axis_y)
		helper_rotate_y(&vector, angle);
	else if (axis == axis_z)
		helper_rotate_z(&vector, angle);
	else
		ft_raise_warning(NULL, "Invalid axis");
	return (vector);
}

t_vector3 			vector3_rotate_euler(t_vector3 vector, t_vector3 angle)
{
	vector = vector3_rotate(vector, axis_y, angle.y);
	vector = vector3_rotate(vector, axis_x, angle.x);
	vector = vector3_rotate(vector, axis_z, angle.z);
	return (vector);
}

t_vector3 			vector3_min(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z)));
}

t_vector3 			vector3_max(t_vector3 a, t_vector3 b)
{
	return (vector3_pack(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z)));
}