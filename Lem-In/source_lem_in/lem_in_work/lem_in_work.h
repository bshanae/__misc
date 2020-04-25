/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_work.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:37:21 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_WORK_H
# define LEM_IN_WORK_H

# include "global_error.h"

# include "lem_in_main.h"
# include "lem_in_eval.h"
# include "lem_in_info.h"

# include "libft_queue.h"

# include <math.h>
# include <limits.h>

void				lem_in_parent_restore(t_lem_in_main *main);
void				lem_in_parent_save(t_lem_in_main *main);

int					lem_in_backtrack(t_lem_in_main *main, t_global_room *start);

void				lem_in_lock_clear(t_lem_in_main *main);
t_global_bool		lem_in_lock_link(t_global_room *from, t_global_room *to);
void				lem_in_lock_path(t_lem_in_main *main, t_global_room *start);
void				lem_in_lock_path_last(t_lem_in_main *main);
void				lem_in_lock_path_all(t_lem_in_main *main);

void				lem_in_solve_conflict(t_lem_in_main *main);

void				lem_in_bfs_prepare(t_lem_in_main *main);
void				lem_in_bfs_see(t_lem_in_main *main, t_global_room *room);
t_global_room		*lem_in_bfs_visit(t_lem_in_main *main);
t_global_bool		lem_in_bfs_check_intersection(t_lem_in_main *main);
t_global_bool		lem_in_bfs_cycle(t_lem_in_main *main);

t_global_bool		lem_in_bfs(t_lem_in_main *main);
void				lem_in_bhandari(t_lem_in_main *main);

void				lem_in_out(t_lem_in_main *main);

void				lem_in_work(t_lem_in_main *main);

#endif
