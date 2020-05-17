#include "scop_math.h"

float				*vector3_array(t_vector3 *vector, int index)
{
	if (index < 0 || index > 3)
		ft_raise_error(NULL, "Bad vector index");
	return (&vector->x + index);
}
