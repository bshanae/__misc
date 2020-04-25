/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:11:04 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:11:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_OBJECT_H
# define GUI_OBJECT_H

# include "global_error.h"
# include "gui_buffer.h"
# include "gui_object_type.h"
# include "gui_object_x_plot.h"
# include "gui_object_x_bundle.h"

# include <stdarg.h>

void				gui_object_plot(t_gui_object_type type, ...);
void				gui_object_plot_bundle(
	t_gui_object_type type, void *bundle);

void				*gui_object_bundle_build(
	void *target, t_gui_object_type type, ...);
void				*gui_object_bundle_build_v(
	void *target, t_gui_object_type type, va_list args);

#endif
