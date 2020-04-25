/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_surface_render.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:32:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:32:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_surface.h"

t_global_bool		gui_surface_render(t_gui_widget *widget, void *ptr)
{
	t_gui_surface	*surface;

	surface = gui_class_cast(widget, gui_class_type_surface);
	gui_object_plot(gui_object_rectangle, widget->render_buffer,
		global_false, surface->min, surface->max,
		widget->render_background, global_true);
	return (global_true);
}
