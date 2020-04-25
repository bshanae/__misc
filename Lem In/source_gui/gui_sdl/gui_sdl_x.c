/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_sdl_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:29:44 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:29:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_sdl.h"

t_gui_sdl			gui_sdl_create(int width, int height)
{
	t_gui_sdl		sdl;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	sdl.window = SDL_CreateWindow("Lem-In GUI",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_SHOWN);
	sdl.renderer = SDL_CreateRenderer(sdl.window, -1, 0);
	sdl.texture_final = SDL_CreateTexture(sdl.renderer,
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	sdl.buffer_final = gui_buffer_new(width, height);
	sdl.buffer_first = gui_buffer_new(width, height);
	sdl.buffer_second = gui_buffer_new(width, height);
	sdl.font_sans14 = gui_font_create(GUI_SOURCE_SANS, 14,
		TTF_STYLE_NORMAL, gui_color_set(GUI_FONT_A_COLOR));
	sdl.font_sans15 = gui_font_create(GUI_SOURCE_SANS, 15,
		TTF_STYLE_NORMAL, gui_color_set(GUI_FONT_A_COLOR));
	sdl.font_sans15_bold = gui_font_create(GUI_SOURCE_SANS, 15,
		TTF_STYLE_BOLD, gui_color_set(GUI_FONT_B_COLOR));
	return (sdl);
}

void				gui_sdl_destroy(t_gui_sdl *sdl)
{
	SDL_DestroyWindow(sdl->window);
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyTexture(sdl->texture_final);
	gui_buffer_delete(&sdl->buffer_final);
	gui_buffer_delete(&sdl->buffer_first);
	gui_buffer_delete(&sdl->buffer_second);
	gui_font_destroy(&sdl->font_sans14);
	gui_font_destroy(&sdl->font_sans15);
	gui_font_destroy(&sdl->font_sans15_bold);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void				gui_sdl_prepare(t_gui_sdl *sdl)
{
	gui_buffer_clear(sdl->buffer_final);
	gui_buffer_copy(sdl->buffer_first, sdl->buffer_final);
	gui_buffer_copy(sdl->buffer_second, sdl->buffer_final);
}

void				gui_sdl_render(t_gui_sdl *sdl)
{
	void			*temp_buffer;
	int				temp_pitch;

	SDL_LockTexture(sdl->texture_final, NULL, &temp_buffer, &temp_pitch);
	ft_memcpy(temp_buffer, sdl->buffer_final->source->pixels,
		sdl->buffer_final->source->pitch * sdl->buffer_final->source->h);
	SDL_UnlockTexture(sdl->texture_final);
	SDL_RenderCopy(sdl->renderer, sdl->texture_final, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
}
