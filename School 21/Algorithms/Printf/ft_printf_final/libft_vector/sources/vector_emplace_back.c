/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_emplace_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:08:12 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:08:13 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						*vector_emplace_back(t_vector *me, ...)
{
	va_list					args;

	if (!me || !me->storage || !me->constructor)
		return (NULL);
	if ((double)(me->length + 1) / (me->capacity) >= VECTOR_ALLOC_LIMIT)
		vector_enlarge(me);
	va_start(args, me);
	me->constructor(me->storage + me->length * me->element_size, args);
	va_end(args);
	me->length++;
	return (vector_at(me, me->length - 1));
}
