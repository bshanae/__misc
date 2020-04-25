/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_system_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:33:33 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:33:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_system.h"

t_gui_system			gui_system_create(void)
{
	t_gui_system		system;

	system.data = vector_create(sizeof(t_gui_widget *));
	return (system);
}
