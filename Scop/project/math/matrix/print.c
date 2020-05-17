#include "scop_math.h"

void				matrix_print(const t_matrix *matrix)
{
	int				i;

	i = 0;
	while (i < 4)
	{
		printf("[%f, %f, %f, %f]",
			matrix->data[i][0],
			matrix->data[i][1],
			matrix->data[i][2],
			matrix->data[i][3]);
		i++;
	}
	printf("\n");
}
