/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_internal_x.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:49:27 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:49:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_LIST_INTERNAL_X_H
# define GUI_LIST_INTERNAL_X_H

# include "gui_button_implementation.h"
# include "gui_list.h"

void				gui_list_internal_load_settings(
	t_gui_list *list, t_gui_list_settings settings);

t_global_bool		gui_list_internal_callback_render(
	t_gui_widget *widget, void *ptr);
t_global_bool		gui_list_internal_callback_scroll(
	t_gui_widget *widget, void *ptr);

void				gui_list_internal_update_block(
	t_gui_list *list, t_gui_widget *widget);

#endif
