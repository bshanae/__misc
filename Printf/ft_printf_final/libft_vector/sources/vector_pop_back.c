/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:10:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:11:36 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_pop_back(t_vector *me)
{
	if (!me || !me->storage || !me->length)
		return ;
	if (me->destructor)
		me->destructor(me->storage + me->element_size * (me->length - 1));
	ft_memset(me->storage + me->element_size * (me->length - 1),
		0, me->element_size);
	me->length--;
}
