#include "scop_math.h"

t_matrix			matrix_empty()
{
	t_matrix		matrix;
	const float 	row[4] = {0, 0, 0, 0};
	int 			i;

	i = 0;
	while (i < 4)
		ft_memcpy(matrix.data[i++], row, sizeof(float) * 4);

	return (matrix);
}