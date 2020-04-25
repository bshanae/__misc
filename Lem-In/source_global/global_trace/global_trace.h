/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_trace.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:59:11 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_TRACE_H
# define GLOBAL_TRACE_H

# include "global_map.h"

# include "libft_vector.h"

typedef struct		s_global_trace
{
	int				number_of_ants;
	int				number_of_cycles;
	t_vector		data;
	t_global_map	*map;
	char			*temp_line;
}					t_global_trace;

t_global_trace		global_trace_create(t_global_map *map);
void				global_trace_destroy(t_global_trace *trace);

void				global_trace_parse(t_global_trace *trace, int fd);
void				global_trace_info(t_global_trace *trace);

void				global_trace_parse_move(t_global_trace *trace);
void				global_trace_parse_group(t_global_trace *trace);

#endif
