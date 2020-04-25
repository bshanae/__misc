/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_control_functions_style.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:40:28 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/27 20:01:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp_control_functions.h"

static void			color_helper(t_ftp_control *ctrl, char *str, int pass)
{
	if (ctrl->buffer.fd == 1)
		buffer_custom_in_str(&ctrl->buffer, str);
	ft_bzero(ctrl->special.color_str, 10);
	ft_strcpy(ctrl->special.color_str, str);
	ctrl->buffer.extern_end += pass;
	if (*ctrl->buffer.extern_end == '!')
	{
		ctrl->special.color_is_const = 1;
		ctrl->buffer.extern_end++;
	}
}

void				ftp_control_color(t_ftp_control *me)
{
	if (!ft_strncmp(me->buffer.extern_end, "red", 3))
		color_helper(me, FTP_RED, 3);
	else if (!ft_strncmp(me->buffer.extern_end, "green", 5))
		color_helper(me, FTP_GREEN, 5);
	else if (!ft_strncmp(me->buffer.extern_end, "yellow", 6))
		color_helper(me, FTP_YELLOW, 6);
	else if (!ft_strncmp(me->buffer.extern_end, "blue", 4))
		color_helper(me, FTP_BLUE, 4);
	else if (!ft_strncmp(me->buffer.extern_end, "magenta", 7))
		color_helper(me, FTP_MAGENTA, 7);
	else if (!ft_strncmp(me->buffer.extern_end, "cyan", 4))
		color_helper(me, FTP_CYAN, 4);
	else if (!ft_strncmp(me->buffer.extern_end, "purple", 6))
		color_helper(me, FTP_PURPLE, 6);
	else if (!ft_strncmp(me->buffer.extern_end, "bold", 4))
		color_helper(me, FTP_BOLD, 4);
	else if (!ft_strncmp(me->buffer.extern_end, "underline", 9))
		color_helper(me, FTP_UNDERLINE, 9);
	else if (!ft_strncmp(me->buffer.extern_end, "reset", 5))
		color_helper(me, FTP_RESET, 5);
}

void				ftp_control_color_clean(t_ftp_control *me)
{
	if (me->special.color_str[0] && !me->special.color_is_const && me->buffer.fd == 1)
		buffer_custom_in_str(&me->buffer, FTP_RESET);
}