/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_trace_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:01:18 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_trace.h"

void				global_trace_parse(t_global_trace *trace, int fd)
{
	char			*line;

	while (global_gnl(fd, &line))
	{
		trace->temp_line = line;
		global_trace_parse_group(trace);
		free(line);
	}
}
