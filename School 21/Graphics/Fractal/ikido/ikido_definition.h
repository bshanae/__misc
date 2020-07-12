/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ikido_definition.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:36:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 20:36:45 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IKIDO_DEFINITION_H
# define IKIDO_DEFINITION_H

# define IKIDO_POINTS		50
# define IKIDO_ITERS		100
# define IKIDO_U			0.8

# define IKIDO_OFFSET_STEP	20
# define IKIDO_ZOOM_STEP	0.45
# define IKIDO_U_STEP		0.01
# define IKIDO_COLOR_STEP	0.5

# include "vector2.h"

typedef struct				s_ikido
{
	t_vector2				random[IKIDO_POINTS];
	t_vector2				offset;
	double					zoom;
	double					u;
	int						width;
	int						height;
}							t_ikido;

#endif
