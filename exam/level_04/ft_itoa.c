#include <stdio.h>
#include <stdlib.h>

char				*ft_itoa(int n)
{
	char			*str;
	int				i;
	long			nn;
	long			div;

	i = 0;
	str = (char *)malloc(12);
	if (n < 0)
	{
		nn = -1 * (long)n;
		str[i++] = '-';
	}
	else
		nn = (long)n;
	div = 1000000000;
	while (!(n / div) && div != 1)
		div /= 10;
	while (div)
	{
		str[i++] = '0' + nn / div;
		nn = nn % div;
		div /= 10;
	}
	str[i] = '\0';
	return (str);
}

int					main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		printf("ft_itoa[%s] = {%s}\n", argv[i], ft_itoa(atoi(argv[i])));
}
