/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_parser_get_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:55:05 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_parser.h"

t_global_range			global_parser_get_range(char **line)
{
	t_global_range		range;

	range.begin = *line;
	global_parser_pass_name(line);
	range.end = *line;
	return (range);
}

int						global_parser_get_int(char **line)
{
	int					value;

	value = ft_atoi(*line);
	global_parser_pass_int(line);
	return (value);
}

t_global_command		global_parser_get_command(char **line)
{
	t_global_command	command;

	command = global_command_none;
	*line += 2;
	if (!ft_strcmp(*line, "start"))
	{
		command = global_command_start;
		*line += 5;
	}
	else if (!ft_strcmp(*line, "end"))
	{
		command = global_command_end;
		*line += 3;
	}
	return (command);
}
