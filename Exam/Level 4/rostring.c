#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int				is_space(const char *c)
{
	return (*c == '\t' ||
			*c == '\n' ||
			*c == ' ');
}

int				is_begin(const char *str, const int *i)
{
	if (!*i && !is_space(str + *i))
		return (1);
	return (*i && is_space(str + *i - 1) && !is_space(str + *i));
}

int				is_end(const char *str, const int *i)
{
	if (!str[*i])
		return (1);
	return (*i && !is_space(str + *i - 1) && is_space(str + *i));
}

typedef struct
{
	int			begin;
	int			end;
}				t_range_i;

int				find_next_word(const char *str, const t_range_i *previous, t_range_i *current)
{
	current->begin = previous->end;
	while (1)
	{
		if (!str[current->begin])
			return (0);
		if (is_begin(str, &current->begin))
			break ;
		current->begin++;
	}
	current->end = current->begin;
	while (!is_end(str, &current->end))
		current->end++;
	return (1);
}

void			print_range(const char *str, const t_range_i *r)
{
	write(1, str + r->begin, r->end - r->begin);
}

void			print_word(const char *str, const t_range_i *r, int *space_need)
{
	if (*space_need)
		write(1, " ", 1);
	else
		*space_need = 1;
	print_range(str, r);
}

void			rostring(const char *str)
{
	int			i;
	t_range_i	previous;
	t_range_i	current;
	t_range_i	first;
	int			space_need;
	
	
	i = 0;
	first.begin = -1;
	previous.end = 0;
	space_need = 0;
	while (1)
	{
		if (!find_next_word(str, &previous, &current))
			break ;
		if (first.begin == -1)
			first = current;
		else
			print_word(str, &current, &space_need);
		previous = current;
	}
	print_word(str, &first, &space_need);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
