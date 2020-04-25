/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:44:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:44:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_EVENT_H
# define GUI_EVENT_H

# include "global_bool.h"
# include "global_error.h"
# include "gui_object_x_plot.h"

# include <SDL.h>

typedef enum				e_gui_event_type
{
	gui_event_type_none,
	gui_event_type_quit,
	gui_event_type_press,
	gui_event_type_release,
	gui_event_type_move,
	gui_event_type_drag,
	gui_event_type_scroll
}							t_gui_event_type;

typedef struct				s_gui_event
{
	SDL_Event				*sdl;
	t_gui_event_type		type;
	t_gui_object_point_i	position;
	t_gui_object_point_i	shift;
}							t_gui_event;

t_gui_event					gui_event_set(SDL_Event *sdl_event);

void						gui_event_update(t_gui_event *event);

#endif
