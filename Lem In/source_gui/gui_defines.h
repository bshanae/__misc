/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:40:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:40:56 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_DEFINES_H
# define GUI_DEFINES_H

# define GUI_WIDTH						720
# define GUI_HEIGHT						480
# define GUI_RENDER_RATE				100

# define GUI_HINT_BACKGROUND			119, 112, 107
# define GUI_HINT_BORDER				187, 188, 183

# define GUI_FONT_A_COLOR				250, 251, 245
# define GUI_FONT_B_COLOR				255, 255, 255

# define GUI_MAP_MIN					(t_gui_object_point_i){0, 0}
# define GUI_MAP_MAX					(t_gui_object_point_i){479, 479}
# define GUI_MAP_BACKGROUND				30, 31, 37
# define GUI_MAP_LINK_COLOR				187, 188, 183
# define GUI_MAP_LINK_COLOR_SELECTED	245, 247, 234
# define GUI_MAP_DRAG_LIMIT				25

# define GUI_BUTTON_ROOM_RADIUS			10
# define GUI_BUTTON_ROOM_COLOR			211, 154, 141
# define GUI_BUTTON_ROOM_COLOR_SPECIAL	57, 210, 170
# define GUI_BUTTON_ROOM_COLOR_SELECTED	245, 247, 234

# define GUI_BUTTON_ANT_RADIUS			6
# define GUI_BUTTON_ANT_RADIUS_PRESSED	5
# define GUI_BUTTON_ANT_COLOR			57, 210, 170
# define GUI_BUTTON_ANT_COLOR_SELECTED	245, 247, 234

# define GUI_BUTTON_ICON_COMPRESS		0.95f
# define GUI_BUTTON_ICON_GREY			0.65

# define GUI_LIST_BUTTON_HEIGHT			20
# define GUI_LIST_BUTTON_SPACING		4
# define GUI_LIST_TEXT_INDENT			10
# define GUI_LIST_SCROLL_ADD_SPACE		5
# define GUI_LIST_SCROLL_MULT			2

# define GUI_LIST_MIN					(t_gui_object_point_i){480, 0}
# define GUI_LIST_MAX					(t_gui_object_point_i){719, 409}
# define GUI_LIST_BACKGROUND			119, 112, 107
# define GUI_LIST_ITEM_COLOR			187, 188, 183
# define GUI_LIST_ITEM_COLOR_SELECTED	245, 247, 234

# define GUI_MENU_MIN					(t_gui_object_point_i){480, 410}
# define GUI_MENU_MAX					(t_gui_object_point_i){719, 479}
# define GUI_MENU_COLOR					119, 112, 107
# define GUI_MENU_MIDDLE_POSITION		(t_gui_object_point_i){600, 445}
# define GUI_MENU_MIDDLE_SIZE			(t_gui_object_point_i){28, 28}
# define GUI_MENU_LEFT_POSITION			(t_gui_object_point_i){550, 445}
# define GUI_MENU_LEFT_SIZE				(t_gui_object_point_i){22, 22}
# define GUI_MENU_RIGHT_POSITION		(t_gui_object_point_i){650, 445}
# define GUI_MENU_RIGHT_SIZE			(t_gui_object_point_i){22, 22}

# define GUI_SOURCE_SANS				"./source_mixed/gui/OpenSans-Light.ttf"
# define GUI_SOURCE_PLAY				"./source_mixed/gui/play.png"
# define GUI_SOURCE_PAUSE				"./source_mixed/gui/pause.png"
# define GUI_SOURCE_LEFT				"./source_mixed/gui/left.png"
# define GUI_SOURCE_RIGHT				"./source_mixed/gui/right.png"

# define GUI_OBJECT_HINT_COLOR_BORDER	gui_color_set(GUI_HINT_BORDER)
# define GUI_OBJECT_HINT_COLOR_FILL		gui_color_set(GUI_HINT_BACKGROUND)
# define GUI_OBJECT_HINT_RECT_HEIGHT	20
# define GUI_OBJECT_HINT_RECT_WIDTH_MIN	14
# define GUI_OBJECT_HINT_TRI_HEIGHT		5
# define GUI_OBJECT_HINT_TRI_WIDTH		10
# define GUI_OBJECT_HINT_CORNER_RADIUS	4

#endif
