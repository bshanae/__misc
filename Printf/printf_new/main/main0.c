#include "ft_printf.h"

typedef struct	s_pair
{
	int 		a;
	int 		b;
}				t_pair;

#include <stdio.h>

void			f(va_list a)
{
	t_pair		t;

	t = va_arg(a, t_pair);
	ft_printf("[%d, %d]", t.a, t.b);
}

int 			main()
{
	t_pair		p = (t_pair){.a = 1, .b = 2};

	ft_printf("{functor : pair}", f);
	ft_printf("hello {functor : pair} world", p);

}