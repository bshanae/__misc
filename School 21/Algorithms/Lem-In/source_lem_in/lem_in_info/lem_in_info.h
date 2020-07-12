/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:40:31 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_INFO_H
# define LEM_IN_INFO_H

# include "lem_in_main.h"

void				lem_in_print_path(t_vector *vector, t_global_bool prefix);
void				lem_in_print_path2(t_vector *path2, t_global_bool prefix);
char				*lem_in_print_state(t_lem_in_state state);
void				lem_in_print_room(t_global_room *room);
void				lem_in_print_eval(t_lem_in_eval *eval,
		t_global_bool prefix);

void				lem_in_info_map(t_lem_in_main *main);

#endif
