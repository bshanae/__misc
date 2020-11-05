/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:04:29 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 14:04:29 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_H
# define LONG_H

# include <libft_vector.h>

typedef struct		s_long
{
	t_vector		vector;
	int				length;
}					t_long;

/*
********************************************************************************
**					BASIC
********************************************************************************
*/

t_long				long_create(u_int init_value);

void				long_destroy(t_long *me);

char				*long_at(t_long *me, int index);

void				long_push_back(t_long *me, u_char value);

void				long_print(t_long *me);

/*
********************************************************************************
**					FUNCTIONS
********************************************************************************
*/

void				long_add(t_long *me, u_int n);

void				long_add_long(t_long *me, t_long *other);

void				long_multiply(t_long *me, u_int n);

#endif
