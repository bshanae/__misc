/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_font.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:44:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:44:45 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_FONT_H
# define GUI_FONT_H

# include "global_error.h"
# include "gui_color.h"

# include "libft_standart.h"

# include <SDL_ttf.h>

typedef struct		s_gui_font
{
	TTF_Font		*data;
	SDL_Color		color;
}					t_gui_font;

t_gui_font			gui_font_create(
	CHAR_REF source, int size, int style, t_gui_color color);
void				gui_font_destroy(t_gui_font *font);

#endif
