/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:05:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:05:55 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_map_x.h"

void					gui_map_delete(t_gui_map **map)
{
	gui_buffer_delete(&(*map)->back_buffer);
	global_map_destroy(&(*map)->data);
	vector_destroy(&(*map)->widgets_rendered);
	vector_destroy(&(*map)->widgets);
	free(*map);
	*map = NULL;
}
