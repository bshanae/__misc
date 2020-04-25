/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_internal_load_x.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:48:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:48:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_list_internal_x.h"

void				gui_list_internal_load_settings(
	t_gui_list *list, t_gui_list_settings settings)
{
	list->settings = gui_list_settings_parse(settings);
}
