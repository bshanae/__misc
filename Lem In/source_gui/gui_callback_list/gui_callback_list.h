/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_callback_list.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:30:46 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:31:13 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CALLBACK_LIST_H
# define GUI_CALLBACK_LIST_H

# include "gui_callback.h"
# include "gui_event.h"

# include "libft_list.h"

typedef t_global_bool			(*t_gui_callback_list_test)(
	struct s_gui_widget *widget, t_gui_event *event);

typedef struct					s_gui_callback_list
{
	t_gui_callback_list_test	test;
	t_list						data;
}								t_gui_callback_list;

t_gui_callback_list				*gui_callback_list_new(
	t_gui_callback_list_test test);
void							gui_callback_list_delete(
	t_gui_callback_list **list);

void							gui_callback_list_push(
	t_gui_callback_list *list, t_gui_callback callback);
t_global_bool					gui_callback_list_pop(
	t_gui_callback_list *list);

t_global_bool					gui_callback_list_test(
	t_gui_callback_list *list, void *widget, t_gui_event *event);
t_global_bool					gui_callback_list_run(
	t_gui_callback_list *list, void *widget);

#endif
