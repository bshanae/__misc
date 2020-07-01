/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:48:20 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:48:22 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "libft_error.h"

# include <stdio.h>

typedef struct		s_core
{
	t_error_config	error_config;
}					t_core;

void				core_start(t_core *core);
void				core_finish(t_core *core);

void				info();

#endif
