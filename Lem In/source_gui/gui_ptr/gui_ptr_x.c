/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_ptr_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:26:49 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:27:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_ptr.h"

t_gui_ptr			gui_ptr_empty(void)
{
	return ((t_gui_ptr){NULL, NULL});
}

t_gui_ptr			gui_ptr_set(void *ptr, t_gui_ptr_release release)
{
	return ((t_gui_ptr){ptr, release});
}

void				gui_ptr_unset(t_gui_ptr *ptr)
{
	ptr->ptr = NULL;
	ptr->ptr = NULL;
}

void				gui_ptr_release(t_gui_ptr *ptr)
{
	if (ptr->release)
		ptr->release(ptr->ptr);
	gui_ptr_unset(ptr);
}
