/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_traverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:09:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:16:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_traverse
	(t_vector *me,
	void functor(void *element, int i, int reverse_i))
{
	size_t					i;

	if (!me || !me->storage)
		return ;
	i = 0;
	while (i < me->length)
	{
		functor(me->storage + (i * me->element_size), i, me->length - 1 - i);
		i++;
	}
}
