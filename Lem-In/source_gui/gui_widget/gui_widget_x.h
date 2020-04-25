/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_widget_x.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:39:53 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:39:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_WIDGET_X_H
# define GUI_WIDGET_X_H

# include "gui_ptr.h"
# include "gui_object_x.h"
# include "gui_callback_list.h"
# include "gui_widget.h"

t_gui_widget		*gui_widget_new(void);
void				gui_widget_delete(t_gui_widget **widget);

int					gui_widget_callback_init(
	t_gui_widget *widget, t_gui_callback_list_test test);
int					gui_widget_callback_init_safe(
	t_gui_widget *widget, t_gui_callback_list_test test, int index);

t_global_bool		gui_widget_callback_pop(
	t_gui_widget *widget, int index);
void				gui_widget_callback_push(
	t_gui_widget *widget, int index, t_gui_callback callback);

t_global_bool		gui_widget_callback_run(
	t_gui_widget *widget, int index, t_gui_event *event, UINT flags);

#endif
