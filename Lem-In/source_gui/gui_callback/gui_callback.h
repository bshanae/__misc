/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_callback.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:24:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:29:01 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CALLBACK_H
# define GUI_CALLBACK_H

# include "global_bool.h"
# include "global_error.h"
# include "gui_ptr.h"

struct s_gui_widget;

typedef t_global_bool		(*t_gui_callback_functor)(
	struct s_gui_widget *, void *);

typedef struct				s_gui_callback
{
	t_gui_callback_functor	functor;
	t_gui_ptr				ptr;
}							t_gui_callback;

t_gui_callback				gui_callback_set(
	t_gui_callback_functor functor,
	void *ptr, t_gui_ptr_release release);
void						gui_callback_unset(
	t_gui_callback *callback);

void						gui_callback_release(t_gui_callback *callback);

#endif
