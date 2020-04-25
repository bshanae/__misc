/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:45:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:45:37 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_LIST_H
# define GUI_LIST_H

# include "gui_defines.h"
# include "gui_settings.h"
# include "gui_system.h"
# include "gui_list_settings.h"

# include "libft_vector.h"

typedef struct					s_gui_list_data
{
	t_vector					buttons;
}								t_gui_list_data;

typedef struct					s_gui_list
{
	t_gui_class_info			info;
	t_gui_surface				*parent;
	t_gui_list_data				data;
	t_gui_list_settings_static	settings;
	t_gui_widget				*unselected;
	t_gui_widget				*selected;
}								t_gui_list;

#endif
