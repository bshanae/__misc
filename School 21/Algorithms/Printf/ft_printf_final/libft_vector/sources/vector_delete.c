/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:08:58 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:08:59 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_delete(t_vector *me, size_t index)
{
	if (!me || !me->storage || index > me->length)
		return ;
	if (me->destructor)
		me->destructor(me->storage + me->element_size * index);
	while (index != me->length)
	{
		ft_memcpy(me->storage + index * me->element_size,
			me->storage + (index + 1) * me->element_size,
			me->element_size);
		index++;
	}
	me->length--;
}
