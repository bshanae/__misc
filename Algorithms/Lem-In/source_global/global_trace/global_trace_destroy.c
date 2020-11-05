/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_trace_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:00:11 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_trace.h"

void				global_trace_destroy(t_global_trace *trace)
{
	int				i;
	t_vector		*ptr;

	i = 0;
	while ((ptr = vector_at(&trace->data, i++)))
		vector_destroy(ptr);
	vector_destroy(&trace->data);
	trace->map = NULL;
}
