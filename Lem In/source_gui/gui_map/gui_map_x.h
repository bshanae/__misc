/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_x.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:07:58 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:07:58 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_MAP_X_H
# define GUI_MAP_X_H

# include "gui_map.h"
# include "gui_button_implementation.h"

# include <limits.h>

t_gui_map			*gui_map_new(int fd);
void				gui_map_delete(t_gui_map **map);

void				gui_map_render_back(t_gui_map *map);
void				gui_map_render_front(t_gui_map *map);

t_global_bool		gui_map_examine_widget(
	t_gui_map *map, t_gui_widget *widget);

#endif
