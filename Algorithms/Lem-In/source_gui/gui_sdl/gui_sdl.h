/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_sdl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:28:33 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:28:34 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SDL_H
# define GUI_SDL_H

# include "global_bool.h"
# include "global_error.h"
# include "gui_defines.h"
# include "gui_buffer.h"
# include "gui_font.h"

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"

typedef struct		s_gui_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture_final;
	t_gui_buffer	*buffer_final;
	t_gui_buffer	*buffer_first;
	t_gui_buffer	*buffer_second;
	t_gui_font		font_sans14;
	t_gui_font		font_sans15;
	t_gui_font		font_sans15_bold;
	SDL_TimerID		timer;
	SDL_Event		event;
}					t_gui_sdl;

t_gui_sdl			gui_sdl_create(int width, int height);
void				gui_sdl_destroy(t_gui_sdl *sdl);

void				gui_sdl_prepare(t_gui_sdl *sdl);
void				gui_sdl_render(t_gui_sdl *sdl);

void				gui_sdl_timer_start(t_gui_sdl *sdl,
	Uint32 interval, SDL_TimerCallback callback, void *ptr);
void				gui_sdl_timer_stop(t_gui_sdl *sdl);

#endif
