/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_line_plot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:23:10 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:23:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

void				gui_object_line_plot(const t_gui_object_line_bundle *bundle)
{
	if (bundle->aa)
		gui_object_line_plot_aa(bundle);
	else
		gui_object_line_plot_naa(bundle);
}
