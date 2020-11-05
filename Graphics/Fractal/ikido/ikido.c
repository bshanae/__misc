/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ikido.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:37:23 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 20:37:23 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ikido.h"

t_ikido				*ikido_new(int width, int height)
{
	t_ikido			*new;

	if (!(new = (t_ikido *)malloc(sizeof(t_ikido))))
		exit(21);
	new->offset = (t_vector2){width / 2., height / 2.};
	new->zoom = 5.;
	new->u = 0.7;
	new->width = width;
	new->height = height;
	return (new);
}

void				ikido_delete(t_ikido **me)
{
	free(*me);
	*me = NULL;
}

void				ikido_rng(t_ikido *me)
{
	int				i;

	srand(time(NULL));
	i = 0;
	while (i < IKIDO_POINTS)
	{
		me->random[i].x = (double)(rand() % me->width);
		me->random[i].y = (double)(rand() % me->height);
		i++;
	}
}
