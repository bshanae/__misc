#include "ftp_control_functions.h"

int 					functor_cmp(const void *mem1, const void *mem2)
{
	const t_ftp_functor	*f1;
	const t_ftp_functor	*f2;

	f1 = mem1;
	f2 = mem2;
	return (ft_strncmp(f1->name, f2->name, 20));
}

#include <stdio.h>

void					ftp_control_functor(t_ftp_control *me)
{
	t_ftp_functor		temp;
	t_ftp_functor		*ptr;
	int 				i;

	if (!me->special.functor_data.storage)
		me->special.functor_data = vector_create(sizeof(t_ftp_functor));
	i = 0;
	while (*me->buffer.extern_end && *me->buffer.extern_end != '}')
	{
		if (i++ >= 20)
			break ;
		temp.name[i] = *(me->buffer.extern_end++);
	}
	if (!(ptr = vector_find(&me->special.functor_data, &temp, functor_cmp)))
	{
		temp.func = va_arg(*me->arg_ptr, void (*)(va_list));
		vector_push_back(&me->special.functor_data, &temp);
	}
	else
		ptr->func(*me->arg_ptr);
}