/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:54:46 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 14:49:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "object.h"
# include "color.h"
# include "ray.h"
# include "light.h"

# define SHADOW_RATIO			2.

typedef struct					s_scene
{
	int							light_mod;
	t_light						lights[16];
	int							lights_length;
	t_vector3					last_hit;
	int							shadow_mod;
	double						shadow_ratio;
}								t_scene;

t_scene							*scene_new(void);

void							scene_delete
								(t_scene **scene);

void							scene_push_light
								(t_scene *me,
								t_vector3 direction,
								double intensity);

#endif
