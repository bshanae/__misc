#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list t_list;

typedef struct	s_list
{
	int     	data;
	t_list		*next;
}				t_list;

t_list			*list_alloc(int data)
{
	t_list		*piece;
	
	if (!(piece = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	piece->data = data;
	piece->next = NULL;
	return (piece);
}

void		push(t_list **l, int n)
{
	t_list	*i;
	
	if (!*l)
	{
		*l = list_alloc(n);
		return ;
	}
	i = *l;
	while (i->next)
		i = i->next;
	i->next = list_alloc(n);
}

void		print(t_list *a)
{
	while (a)
	{
		printf("[%d]", a->data);
		if (a->next)
			printf(" -> ");
		a = a->next;
	}
	printf("\n");
}

t_list			*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list		*start;
	t_list		*iter;
	int			temp;
	
	start = lst;
	while (start->next)
	{
		iter = start;
		while (iter->next)
		{
			if (!cmp(iter->data, iter->next->data))
			{
				temp = iter->data;
				iter->data = iter->next->data;
				iter->next->data = temp;
			}
			iter = iter->next;
		}
		start = start->next;
	}
	return (lst);
}

int				asc(int a, int b)
{
	return (a <= b);
}

int				main(void)
{
	t_list		*a = NULL;
	
	push(&a, -1);
	push(&a, 2);
	push(&a, -42);
	push(&a, 1);
	push(&a, 3);
	push(&a, 2);
	print(a);
	sort_list(a, asc);
	print(a);
}

