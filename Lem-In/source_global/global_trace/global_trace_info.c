/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_trace_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:00:47 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_trace.h"

void				global_trace_info(t_global_trace *trace)
{
	int				i[2];
	t_vector		*path;
	t_global_room	**room2;
	t_global_room	*room;

	ft_printf("[Global trace] :\n");
	ft_printf("{\n");
	i[0] = 0;
	while ((path = vector_at(&trace->data, i[0]++)))
	{
		ft_printf("\t{");
		i[1] = 0;
		while ((room2 = vector_at(path, i[1]++)))
		{
			room = *room2;
			ft_printf("'%s'", room->name);
			if (i[1] != path->length)
				ft_printf(" -> ");
		}
		ft_printf("}");
		if (i[0] != trace->data.length)
			ft_printf(", ");
		ft_printf("\n");
	}
	ft_printf("}\n");
}
