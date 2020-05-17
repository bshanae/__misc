#include "scop_math.h"

t_matrix			matrix_product(t_matrix a, t_matrix b)
{
	t_matrix		matrix;
	float			num;
	int				i;
	int				j;
	int				k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			num = 0;
			k = 0;
			while (k < 4)
			{
				num += a.data[k][j] * b.data[i][k];
				k++;
			}
			matrix.data[i][j++] = num;
		}
		i++;
	}
	return (matrix);
}

t_matrix			matrix_product_multiple(int number, ...)
{
	t_matrix		final;
	va_list			args;

	ft_assert(NULL, number > 0,
		"Invalid number of arguments for matrix multiplication");
	final = matrix_identity();
	va_start(args, number);
	while (number-- > 0)
		final = matrix_product(final, va_arg(args, t_matrix));
	va_end(args);
	return (final);
}
