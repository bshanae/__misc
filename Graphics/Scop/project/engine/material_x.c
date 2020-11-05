/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:50:10 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:50:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_material			material_create(const char *name)
{
	t_material		material;

	material.name = ft_malloc(NULL, ft_strlen(name) + 1);
	ft_strcpy(material.name, name);
	material.texture = 0;
	material.ambient = vector3_pack(0, 0, 0);
	material.diffuse = vector3_pack(1, 1, 1);
	material.specular = vector3_pack(0, 0, 0);
	material.specular_exponent = 1;
	material.alpha = 1;
	return (material);
}

void				material_destroy(t_material *material)
{
	free(material->name);
	texture_destroy(&material->texture);
}
