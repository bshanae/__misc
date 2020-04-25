/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_sdl_timer_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:28:59 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:29:01 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_sdl.h"

void				gui_sdl_timer_start(
	t_gui_sdl *sdl, Uint32 interval, SDL_TimerCallback callback, void *ptr)
{
	sdl->timer = SDL_AddTimer(interval, callback, ptr);
}

void				gui_sdl_timer_stop(t_gui_sdl *sdl)
{
	SDL_RemoveTimer(sdl->timer);
}
