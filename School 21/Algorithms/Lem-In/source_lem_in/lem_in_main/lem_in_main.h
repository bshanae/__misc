/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_main.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:32:41 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_MAIN_H
# define LEM_IN_MAIN_H

# include "global_error.h"
# include "global_bool.h"
# include "global_map.h"
# include "lem_in_plugin.h"
# include "lem_in_eval.h"

# include "libft_vector.h"
# include "libft_queue.h"

typedef enum			e_lem_in_bfs_state
{
	lem_in_bfs_normal,
	lem_in_bfs_intersection,
	lem_in_bfs_confirmed_intersection
}						t_lem_in_bfs_state;

typedef struct			s_lem_in_main
{
	int					fd;
	t_global_bool		print_only;
	t_global_map		map;
	t_queue				bfs_queue;
	t_global_room		*bfs_current_room;
	t_lem_in_plugin		*bfs_current_plugin;
	t_lem_in_bfs_state	bhandari_state;
	t_global_room		*bhandari_intersection;
	t_vector			bhandari_length_array;
	t_vector			bhandari_length_array_test;
	t_lem_in_eval		bhandari_eval;
	t_lem_in_eval		bhandari_eval_test;
	t_vector			bhandari_paths;
	int					out_ant_current;
	int					out_ant_next;
	int					out_is_first_in_row;
}						t_lem_in_main;

# define LEM_IN_NO_ANT	0

#endif
