/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_parser_is_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:55:34 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_parser.h"

t_global_bool		global_parser_is_comment(char *line)
{
	return (line[0] == '#' && line[1] != '#');
}

t_global_bool		global_parser_is_room(char *line)
{
	global_parser_verify_name(line);
	global_parser_pass_name(&line);
	if (*(line++) != ' ')
		return (global_false);
	global_parser_pass_int(&line);
	if (*(line++) != ' ')
		return (global_false);
	global_parser_pass_int(&line);
	if (*line != '\0')
		return (global_false);
	return (global_true);
}

t_global_bool		global_parser_is_link(char *line)
{
	global_parser_verify_name(line);
	global_parser_pass_name(&line);
	if (*(line++) != '-')
		return (global_false);
	global_parser_verify_name(line);
	global_parser_pass_name(&line);
	if (*(line++) != '\0')
		return (global_false);
	return (global_true);
}

t_global_bool		global_parser_is_command(char *line)
{
	return (line[0] == '#' && line[1] == '#');
}
