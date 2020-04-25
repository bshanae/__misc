/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_class_info_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:32:46 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:32:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_class.h"

t_gui_class_info		gui_class_info_set(t_gui_class_type type)
{
	return ((t_gui_class_info){gui_class_pattern_get(type), type});
}
