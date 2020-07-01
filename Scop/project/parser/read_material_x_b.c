/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_material_x_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:29:00 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 14:29:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void					read_material_transparent(t_parser *parser)
{
	fill_float(
		parser->material.current_line + ft_strlen(SCOP_MATERIAL_TRANSPARENT),
		1, &parser->material.current_material->alpha);
	parser->material.current_material->alpha =
		1.f - parser->material.current_material->alpha;
}

void					read_material_dissolve(t_parser *parser)
{
	fill_float(
		parser->material.current_line + ft_strlen(SCOP_MATERIAL_DISSOLVE),
		1, &parser->material.current_material->alpha);
}
