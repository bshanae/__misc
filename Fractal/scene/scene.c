/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:55:07 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 14:49:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene				*scene_new(void)
{
	t_scene			*new;

	if (!(new = (t_scene *)malloc(sizeof(t_scene))))
		exit(21);
	new->light_mod = 1;
	new->lights_length = 0;
	new->shadow_mod = 1;
	new->shadow_ratio = SHADOW_RATIO;
	return (new);
}

void				scene_delete(t_scene **scene)
{
	free(*scene);
	*scene = NULL;
}

void				scene_push_light
	(t_scene *me, t_vector3 direction, double intensity)
{
	vector3_normalize(&direction);
	me->lights[me->lights_length++] = (t_light){direction,
												vector3_mul(&direction, -1.),
												intensity};
}
