/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:06:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 14:06:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VECTOR_H
# define LIBFT_VECTOR_H

# include "libft_standart.h"

# include <stdarg.h>

# define VECTOR_ALLOC_INIT	10
# define VECTOR_ALLOC_MULT	2
# define VECTOR_ALLOC_LIMIT	0.5

typedef struct				s_vector
{
	void					*storage;
	size_t					element_size;
	size_t					capacity;
	size_t					length;
	void					(*constructor)(void *, va_list);
	void					(*destructor)(void *ptr);
}							t_vector;

t_vector					vector_create
	(size_t element_size,
	void (*constructor)(void *, va_list),
	void (*destructor)(void *));

void						vector_destroy(t_vector *me);

void						vector_enlarge(t_vector *me);

void						*vector_at(t_vector *me, size_t index);

void						*vector_push_back(t_vector *me, void *data);

void						*vector_emplace_back(t_vector *me, ...);

void						vector_pop_back(t_vector *me);

void						vector_insert
	(t_vector *me, size_t i_dest, void *data);

void						vector_delete(t_vector *me, size_t index);

void						vector_clear(t_vector *me);

void						vector_traverse
	(t_vector *me,
	void functor(void *element, int i, int reverse_i));

#endif
