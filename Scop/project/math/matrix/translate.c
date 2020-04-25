#include "scop_math.h"

t_matrix			matrix_translate(t_vector3 value)
{
	t_matrix		matrix;
	int 			i;

	matrix = matrix_identity();
	i = 0;
	while (i < 3)
	{
		matrix.data[3][i] = *vector3_value(&value, i);
		i++;
	}
	return (matrix);
}
