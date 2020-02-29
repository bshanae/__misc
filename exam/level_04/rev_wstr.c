#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int				is_space(char c)
{
	return (c == '\n' || c == '\t' || c == ' ');
}

int				is_begin(const char *s, int i)
{
	if (!i && !is_space(s[i]))
		return (1);
	if (i > 0 && !is_space(s[i]) && is_space(s[i - 1]))
		return (1);
	return (0);
}

int				is_end(const char *s, int i)
{
	if (i > 0 && !s[i] && !is_space(s[i - 1]))
		return (1);
	if (i > 0 && is_space(s[i]) && !is_space(s[i - 1]))
		return (1);
	return (0);
}

void			put_range(const char *begin, const char *end)
{
	write(1, begin, end - begin);
}
	
void			rev_wstr(const char *s)
{
	int			is_first;
	int			right;
	int			left;
	
	is_first = 1;
	right = 0;
	while (s[right])
		right++;
	while (1)
	{
		while (!is_end(s, right))
			if (-- right < 0)
				return ;
		left = right;
		while (!is_begin(s, left))
			if (--left < 0)
				return ;
		if (!is_first)
			write(1, " ", 1);
		else
			is_first = 0;
		put_range(s + left, s + right);
		right = left - 1;
	}
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
}
