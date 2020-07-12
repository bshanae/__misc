/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_ctrl_ikido.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:52:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 20:52:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm.h"

int					rm_ctrl_ikido(t_rm *me, int key)
{
	if (me->mod != MOD_IKIDO)
		return (0);
	if (key == KEY_A)
		me->ikido->offset.x += IKIDO_OFFSET_STEP;
	else if (key == KEY_D)
		me->ikido->offset.x -= IKIDO_OFFSET_STEP;
	else if (key == KEY_W)
		me->ikido->offset.y += IKIDO_OFFSET_STEP;
	else if (key == KEY_S)
		me->ikido->offset.y -= IKIDO_OFFSET_STEP;
	else if (key == KEY_PLUS_1)
		me->ikido->zoom += IKIDO_ZOOM_STEP;
	else if (key == KEY_MINUS_1)
		me->ikido->zoom -= IKIDO_ZOOM_STEP;
	else if (key == KEY_Q)
		me->ikido->u = fmin(me->ikido->u + IKIDO_U_STEP, 0.95);
	else if (key == KEY_E)
		me->ikido->u = fmax(me->ikido->u - IKIDO_U_STEP, 0.);
	else
		return (0);
	return (1);
}
