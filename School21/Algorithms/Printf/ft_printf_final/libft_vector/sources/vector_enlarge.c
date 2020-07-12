/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_enlarge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:09:23 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:09:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_enlarge(t_vector *me)
{
	void					*new_storage;
	size_t					new_capacity;

	if (!me)
		return ;
	new_capacity = me->capacity * VECTOR_ALLOC_MULT;
	new_storage = malloc(new_capacity * me->element_size);
	if (!new_storage)
		return ;
	ft_memcpy(new_storage, me->storage, me->length * me->element_size);
	free(me->storage);
	me->storage = new_storage;
	me->capacity = new_capacity;
}
