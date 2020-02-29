#include <stdio.h>
#include <stdlib.h>

int				is_first = 1;

int				is_prime(int x)
{
	if (x <= 3)
		return (x > 1);
	else if (!(x % 2) || !(x % 3))
		return (0);
	for (int i = 5; i * i <= x; i += 6)
		if (!(x % i) || !(x % (i + 2)))
			return (0);
	return (1);	
}

int				next_prime(int x)
{
	x++;
	while (!is_prime(x))
		x++;
	return (x);
}

void			fprime(int x)
{
	int			factor;

	if (x == 1)
	{
		printf("1");
		return ;
	}
	factor = 2;
	while (factor <= x)
	{
		if (!(x % factor))
		{
			if (is_first)
				is_first = 0;
			else 
				printf("*");
			printf("%d", factor);
			x /= factor;
		}
		if (x % factor)
			factor = next_prime(factor);
	}
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
}
