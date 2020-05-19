#include "parser.h"

t_bool					helper_next(const char **line)
{
	while (is_float(*line))
		(*line)++;
	while (**line && !is_float(*line))
		(*line)++;
	return (**line != '\0');
}

void					fill_float(const char *in, int length, float *out)
{
	if (!is_float(in) && !helper_next(&in))
		ft_raise_error(NULL, "Can't parse vector");
	while (1)
	{
		*(out++) = (float)ft_atof(in, NULL);
		if (!--length)
			break ;
		if (!helper_next(&in))
			ft_raise_error(NULL, "Can't parse vector");
	}
}

t_interim_vertex		fill_interim_vertex(const char *in)
{
	t_interim_vertex	vertex;
	int					*out;
	int					count;

	vertex = (t_interim_vertex){-1, -1, -1};
	out = &vertex.vertex;
	count = 0;
	while (1)
	{
		if (is_integer(in))
			*out = ft_atoi(in) - 1;
		out++;
		if (++count == 3)
			break ;
		while (is_integer(in))
			in++;
		if (*(in++) != '/')
			break ;
	}
	return (vertex);
}
