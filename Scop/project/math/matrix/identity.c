#include "scop_math.h"

t_matrix			matrix_identity()
{
	t_matrix		matrix;
	int 			i;

	matrix = matrix_empty();
	i = 0;
	while (i < 4)
	{
		matrix.data[i][i] = 1.f;
		i++;
	}
	return (matrix);
}