#include <unistd.h>
#include <stdio.h>

typedef unsigned char 	u_char;
typedef unsigned int 	u_int;

char					hex_alphabet[16] = "0123456789abcdef";

#define MIN(a,b) (a < b ? (a) : (b))

void					print_byte(const u_char *x)
{
	short				num;
	
	num = *x;
	for (int i = 0; i < 2; i++)
	{
		printf("%c", hex_alphabet[num / 16]);
		num %= 16;
	}
}

void					print_str(const u_char *s)
{
	s = 0;
}

void					print_memory(const void *data, size_t size)
{
	u_char				*begin;
	u_char				*i[2];
	long				size_l;
	
	begin = (u_char *)data;
	i[0] = begin;
	size_l = (long)size;
	while (i[0] - begin <= size_l)
	{
		i[1] = i[0];
		while (i[1] - begin <= size_l && i[1] - i[0] < 16)
		{
			print_byte(i[1]++);
			if (!(i[1] - i[0]) % 4)
				printf(" ");
			i[1]++;
		}
		printf("\n");
		print_str(i[0]);
		i[0] = i[1];;
	}
}

int						main()
{
	int	tab[10] = {0, 23, 150, 255,
		12, 16,  21, 42};
	
	print_memory(tab, sizeof(tab));
	return (0);
}
