/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:06:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:06:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_clear(t_vector *me)
{
	size_t					i;

	if (!me || !me->storage || !me->length)
		return ;
	if (me->destructor)
	{
		i = 0;
		while (i < me->length)
			me->destructor(me->storage + (me->element_size * i++));
	}
	ft_memset(me->storage, 0, me->length * me->element_size);
	me->length = 0;
}
