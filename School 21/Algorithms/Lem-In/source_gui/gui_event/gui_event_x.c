/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_event_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:44:20 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:44:20 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_event.h"

t_gui_event			gui_event_set(SDL_Event *sdl_event)
{
	t_gui_event		event;

	event.sdl = sdl_event;
	event.type = gui_event_type_none;
	event.position.x = -1;
	event.position.y = -1;
	event.shift.x = -1;
	event.shift.y = -1;
	return (event);
}

static int			helper_motion(t_gui_event *event)
{
	if (event->sdl->type == SDL_MOUSEMOTION)
	{
		event->position.x = event->sdl->motion.x;
		event->position.y = event->sdl->motion.y;
		if (event->sdl->motion.state == SDL_BUTTON_LEFT)
			event->type = gui_event_type_drag;
		else
			event->type = gui_event_type_move;
		event->shift.x = event->sdl->motion.xrel;
		event->shift.y = event->sdl->motion.yrel;
		return (1);
	}
	return (0);
}

void				gui_event_update(t_gui_event *event)
{
	if (event->sdl->type == SDL_QUIT)
		event->type = gui_event_type_quit;
	else if (event->sdl->type == SDL_MOUSEBUTTONDOWN &&
		event->sdl->button.button == SDL_BUTTON_LEFT)
		event->type = gui_event_type_press;
	else if (event->sdl->type == SDL_MOUSEBUTTONUP &&
		event->sdl->button.button == SDL_BUTTON_LEFT)
		event->type = gui_event_type_release;
	else if (helper_motion(event))
		;
	else if (event->sdl->type == SDL_MOUSEWHEEL)
	{
		event->type = gui_event_type_scroll;
		event->shift.x = event->sdl->wheel.x;
		event->shift.y = event->sdl->wheel.y;
	}
	else
		event->type = gui_event_type_none;
}
