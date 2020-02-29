#include <stdio.h>

int				brackets(const char *str)
{
	char		buffer[4096];
	int			i;
	
	i = 0;
	while (*str)
	{
		if (*str == '(')
			buffer[i++] = ')';
		else if (*str == '[')
			buffer[i++] = ']';
		else if (*str == '{')
		buffer[i++] = '}';
		else if (*str == ')' || *str == ']' || *str == '}')
			if (buffer[--i] != *str)
				return (0);
		str++;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		if (brackets(argv[i]))
			printf("OK\n");
		else
			printf("Error\n");
}
