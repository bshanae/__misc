/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_additional.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:52:21 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:52:21 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp_format_in.h"

#define READ_SIZE 500

/*
********************************************************************************
**				This function doesn't do anything, because function "read"
**				is forbidden. To make this function work paste following code in
**				while body, after if statement and delete return in the
**				beginning of teh function
**
**				if (!(res = read(fd, ctrl->buffer.iter, READ_SIZE)))
**					break ;
********************************************************************************
*/

static void		read_file(t_ftp_control *ctrl, int fd)
{
	int			res;

	return ;
	if (read(fd, ctrl->buffer.iter, 0) < 0)
	{
		buffer_custom_in_str(&ctrl->buffer, "(error)");
		return ;
	}
	while (1)
	{
		if (ctrl->buffer.iter + READ_SIZE >= ctrl->buffer.end)
			buffer_out(&ctrl->buffer);
		ctrl->buffer.iter += res;
	}
}

int				ftp_format_in_additional(t_ftp_control *ctrl)
{
	int			fd;

	if (!ft_strncmp(ctrl->buffer.extern_end, "fd_in", 5))
	{
		fd = va_arg(*ctrl->arg_ptr, int);
		ctrl->buffer.extern_end += 5;
		read_file(ctrl, fd);
	}
	else if (!ft_strncmp(ctrl->buffer.extern_end, "fd_out", 6))
	{
		fd = va_arg(*ctrl->arg_ptr, int);
		ctrl->buffer.extern_end += 6;
		if (fd > 0)
			ctrl->buffer.fd = fd;
		else
			buffer_custom_in_str(&ctrl->buffer, "(error)");
	}
	else
		return (0);
	return (1);
}