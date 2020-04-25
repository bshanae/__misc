/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_system_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:33:24 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:33:24 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_system.h"

t_vector_iter		gui_system_add(t_gui_system *system, t_gui_widget *widget)
{
	return (vector_push(&system->data, &widget));
}
