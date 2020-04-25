#include "scop_math.h"

t_matrix			matrix_product(t_matrix a, t_matrix b)
{
	t_matrix		matrix;
	float			num;

	matrix = (t_matrix){};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			num = 0;
			for (int k = 0; k < 4; k++)
				num += a.data[k][j] * b.data[i][k];
			matrix.data[i][j] = num;
		}
	}
	return (matrix);
}

t_matrix			matrix_product_multiple(int number, ...)
{
	t_matrix		final;
	va_list			args;

	ft_assert(NULL, number > 0, "Invalid number of arguments for matrix multiplication");
	final = matrix_identity();
	va_start(args, number);
	while (number-- > 0)
		final = matrix_product(final, va_arg(args, t_matrix));
	va_end(args);
	return (final);
}