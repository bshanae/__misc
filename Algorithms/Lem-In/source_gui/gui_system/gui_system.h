/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_system.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:33:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:33:03 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SYSTEM_H
# define GUI_SYSTEM_H

# include "g_settings.h"
# include "gui_widget_x.h"

# include "libft_vector.h"

typedef struct		s_gui_system
{
	t_vector		data;
}					t_gui_system;

t_gui_system		gui_system_create();
void				gui_system_destroy(t_gui_system *system);

t_vector_iter		gui_system_add(t_gui_system *system, t_gui_widget *widget);
void				gui_system_remove(t_gui_system *system, int index);

t_global_bool		gui_system_signal_test(
	t_gui_system *system, t_gui_widget *widget);
t_global_bool		gui_system_signal_send(
	t_gui_system *system, t_gui_widget *widget);
t_global_bool		gui_system_run_event(t_gui_system *system);

#endif
