#include "scop_math.h"

t_matrix			matrix_scale(float value)
{
	t_matrix		matrix;
	int				i;

	matrix = matrix_identity();
	i = 0;
	while (i < 3)
	{
		matrix.data[i][i] = value;
		i++;
	}
	return (matrix);
}
