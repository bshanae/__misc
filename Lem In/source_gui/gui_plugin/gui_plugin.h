/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_plugin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:26:32 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:26:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_PLUGIN_H
# define GUI_PLUGIN_H

# include "global_error.h"
# include "global_bool.h"
# include "gui_widget_x.h"

typedef struct					s_gui_plugin
{
	t_global_bool				highlight;
	t_gui_widget				*widget;
}								t_gui_plugin;

t_gui_plugin					*global_room_plugin_new(t_gui_widget *widget);

#endif
