/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:54:51 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_PARSER_H
# define GLOBAL_PARSER_H

# include "global_bool.h"
# include "global_range.h"
# include "global_command.h"
# include "global_error.h"

# include "libft_standart.h"

void				global_parser_verify_name(char *line);

void				global_parser_pass_name(char **line);
void				global_parser_pass_int(char **line);

t_global_bool		global_parser_is_comment(char *line);
t_global_bool		global_parser_is_room(char *line);
t_global_bool		global_parser_is_link(char *line);
t_global_bool		global_parser_is_command(char *line);

t_global_range		global_parser_get_range(char **line);
int					global_parser_get_int(char **line);
t_global_command	global_parser_get_command(char **line);

#endif
