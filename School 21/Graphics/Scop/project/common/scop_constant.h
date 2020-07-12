/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_constant.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 23:20:00 by bshanae           #+#    #+#             */
/*   Updated: 2020/06/24 23:20:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_CONSTANT_H
# define SCOP_CONSTANT_H

# define SCOP_EPSILON				0.001f

# define SCOP_AXIS_X				(t_vector3){1, 0, 0}
# define SCOP_AXIS_Y				(t_vector3){0, 1, 0}
# define SCOP_AXIS_Z				(t_vector3){0, 0, 1}

# define SCOP_MODEL_COMMENT			"# "
# define SCOP_MODEL_EMPTY			" "
# define SCOP_MODEL_VERTEX			"v "
# define SCOP_MODEL_TEXTURE			"vt "
# define SCOP_MODEL_NORMAL			"vn "
# define SCOP_MODEL_FACE			"f "
# define SCOP_MODEL_LIBRARY			"mtllib "
# define SCOP_MODEL_MATERIAL		"usemtl "

# define SCOP_MATERIAL_NEW			"newmtl "
# define SCOP_MATERIAL_TEXTURE		"map_Kd "
# define SCOP_MATERIAL_AMBIENT		"Ka "
# define SCOP_MATERIAL_DIFFUSE		"Kd "
# define SCOP_MATERIAL_SPECULAR		"Ks "
# define SCOP_MATERIAL_EXPONENT		"Ns "
# define SCOP_MATERIAL_TRANSPARENT	"Tr "
# define SCOP_MATERIAL_DISSOLVE		"d "

# define SCOP_MOD_RGB				0
# define SCOP_MOD_RANDOM			1
# define SCOP_MOD_MATERIAL			2
# define SCOP_MOD_TEXTURE			3

#endif
