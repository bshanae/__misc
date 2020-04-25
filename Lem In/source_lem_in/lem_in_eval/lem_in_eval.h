/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_eval.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:36:53 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_EVAL_H
# define LEM_IN_EVAL_H

# include "global_bool.h"
# include "global_room.h"

# include <math.h>

typedef struct		s_lem_in_eval
{
	t_global_bool	is_valid;
	int				number_of_ants;
	t_vector		*array;
	int				cost;
	t_vector		distribution;
}					t_lem_in_eval;

t_lem_in_eval		lem_in_eval_create(t_vector *array, int number_of_ants);
void				lem_in_eval_destroy(t_lem_in_eval *eval);

#endif
