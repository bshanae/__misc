/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_class_cast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:34:30 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:34:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_class.h"

void				*gui_class_cast(
	void *object, t_gui_class_type target_type)
{
	int				direction;

	direction = (int)target_type - (int)((t_gui_class_info *)object)->type;
	return (gui_class_cast_directed(object, direction, target_type));
}
