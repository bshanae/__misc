/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_callback_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:25:05 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:25:06 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_callback.h"

t_gui_callback		gui_callback_set(
	t_gui_callback_functor functor,
	void *ptr, t_gui_ptr_release release)
{
	return (t_gui_callback){functor, gui_ptr_set(ptr, release)};
}

void				gui_callback_unset(t_gui_callback *callback)
{
	callback->functor = NULL;
	callback->ptr = gui_ptr_empty();
}

void				gui_callback_release(t_gui_callback *callback)
{
	gui_ptr_release(&callback->ptr);
	gui_callback_unset(callback);
}
