/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_control_definition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:43:15 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/27 20:21:23 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp_control_functions.h"

int				ftp_control_init
	(t_ftp_control *me, const char *extern_begin, va_list *arg_ptr)
{
	if (!extern_begin)
		return (FTP_ERR_FORMAT);
	if (!me->buffer.begin)
	{
		if ((buffer_init(&me->buffer, extern_begin)) == -1)
			return (FTP_ERR_ALLOC);
	}
	else
		buffer_reset(&me->buffer, extern_begin);
	me->arg_ptr = arg_ptr;
	if (!me->special.color_is_const)
		ft_bzero(me->special.color_str, 10);
	else
	{
		if (me->buffer.iter + ft_strlen(me->special.color_str) >= me->buffer.end)
			buffer_out(&me->buffer);
		ft_memcpy(me->buffer.iter,
			me->special.color_str, ft_strlen(me->special.color_str));
		me->buffer.iter += ft_strlen(me->special.color_str);
	}
//	if (me->special.cmd_data.storage)
//		me->special.cmd_data = vector_create(sizeof(void (*)(void *, ...)), 0, 0); //todo change vector create function

	return (0);
}
