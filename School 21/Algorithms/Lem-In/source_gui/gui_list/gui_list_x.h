/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_x.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:50:33 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:50:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_LIST_X_H
# define GUI_LIST_X_H

# include "gui_button_implementation.h"
# include "gui_list.h"

typedef enum		e_gui_list_signal
{
	gui_list_signal_select = gui_surface_signal_end,
	gui_list_signal_unselect,
}					t_gui_list_signal;

t_gui_list			*gui_list_new(t_gui_list_settings settings);
t_gui_list			*gui_list_new_default(
	t_gui_object_point_i min, t_gui_object_point_i max);

void				gui_list_push(
	t_gui_list *list, CHAR_REF str, t_gui_ptr ptr);
void				gui_list_select(t_gui_list *list, int index);

#endif
