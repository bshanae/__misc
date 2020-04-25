/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:10:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:10:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_math.h"

float				gui_ipart(float x)
{
	return (floorf(x));
}

float				gui_round(float x)
{
	return (gui_ipart(x + 0.5f));
}

float				gui_fpart(float x)
{
	return (x - floorf(x));
}

float				gui_rfpart(float x)
{
	return (1.f - gui_fpart(x));
}
