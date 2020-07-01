/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:07:29 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:07:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

t_vector					vector_create
	(size_t element_size,
	void (*constructor)(void *, va_list),
	void (*destructor)(void *))
{
	t_vector				vector;

	vector.storage = NULL;
	vector.element_size = 0;
	vector.capacity = 0;
	vector.length = 0;
	vector.constructor = NULL;
	vector.destructor = NULL;
	vector.storage = malloc(element_size * VECTOR_ALLOC_INIT);
	if (!vector.storage)
		return (vector);
	vector.element_size = element_size;
	vector.capacity = VECTOR_ALLOC_INIT;
	vector.constructor = constructor;
	vector.destructor = destructor;
	return (vector);
}