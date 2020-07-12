/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_type.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:12:03 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:12:15 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_OBJECT_TYPE_H
# define GUI_OBJECT_TYPE_H

typedef enum		e_gui_object_type
{
	gui_object_undefined,
	gui_object_point_i,
	gui_object_point_f,
	gui_object_line,
	gui_object_circle,
	gui_object_rectangle,
	gui_object_hint
}					t_gui_object_type;

#endif
