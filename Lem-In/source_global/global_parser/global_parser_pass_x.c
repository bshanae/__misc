/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_parser_pass_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:56:08 by enikole           #+#    #+#             */
/*   Updated: 2019/12/18 14:51:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_parser.h"

void				global_parser_pass_name(char **line)
{
	while (is_alpha(*line) || is_dec(*line) || **line == '_')
		(*line)++;
}

void				global_parser_pass_int(char **line)
{
	while (is_dec(*line))
		(*line)++;
}
