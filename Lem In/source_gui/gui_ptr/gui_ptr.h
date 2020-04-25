/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_ptr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:27:29 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:28:10 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_PTR_H
# define GUI_PTR_H

# include "global_error.h"

typedef void			(*t_gui_ptr_release)(void *);

typedef struct			s_gui_ptr
{
	void				*ptr;
	t_gui_ptr_release	release;
}						t_gui_ptr;

t_gui_ptr				gui_ptr_empty();

t_gui_ptr				gui_ptr_set(void *ptr, t_gui_ptr_release release);
void					gui_ptr_unset(t_gui_ptr *ptr);

void					gui_ptr_release(t_gui_ptr *ptr);

#endif
