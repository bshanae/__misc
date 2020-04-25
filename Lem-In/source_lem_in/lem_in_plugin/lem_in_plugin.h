/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_plugin.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:43:06 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_PLUGIN_H
# define LEM_IN_PLUGIN_H

# include "lem_in_state.h"

typedef struct		s_lem_in_plugin
{
	t_lem_in_state	state;
	t_global_room	*parent_current;
	t_global_room	*parent_best;
	t_global_bool	is_parent_important;
	t_global_bool	ignore_best_parent;
	t_vector		lock;
	int				ant;
}					t_lem_in_plugin;

#endif
