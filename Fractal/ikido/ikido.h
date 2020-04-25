/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ikido.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:36:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 20:36:57 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IKIDO_H
# define IKIDO_H

# include "vector2.h"

# include "ikido_definition.h"

# include <stdlib.h>
# include <time.h>

t_ikido					*ikido_new(int width, int height);

void					ikido_delete(t_ikido **me);

void					ikido_rng(t_ikido *me);

#endif
