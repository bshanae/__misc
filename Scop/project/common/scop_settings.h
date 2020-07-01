/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_settings.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:47:02 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:47:05 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_SETTINGS_H
# define SCOP_SETTINGS_H

# define SCOP_WINDOW_WIDTH				1280
# define SCOP_WINDOW_HEIGHT				720
# define SCOP_WINDOW_NAME				"scop"

# define SCOP_BACKGROUND				0.1, 0.1, 0.1, 1

# define SCOP_VERTEX_SHADER				"project/resources/vertex.glsl"
# define SCOP_FRAGMENT_SHADER			"project/resources/fragment.glsl"

# define SCOP_VAO_ATTRIBUTE_NUMBER		5

# define SCOP_CAMERA_FOV				45
# define SCOP_CAMERA_POSITION			vector3_pack(0, 0, 15)
# define SCOP_CAMERA_DIRECTION			vector3_pack(0, 0, -1)
# define SCOP_CAMERA_NEAR				0.1
# define SCOP_CAMERA_FAR				1000
# define SCOP_CAMERA_MOVEMENT_SPEED		0.5f
# define SCOP_CAMERA_ROTATION_SPEED		0.05f

# define SCOP_TARGET_MOVEMENT_SPEED		0.5f
# define SCOP_TARGET_ROTATION_SPEED		0.1f

# define SCOP_MODEL_SCALE_STEP			0.05f
# define SCOP_MODEL_SCALE_MIN			0.05f
# define SCOP_MODEL_SCALE_MAX			10.f

# define SCOP_MODEL_ROTATION_FREQUENCY	1500
# define SCOP_MODEL_ROTATION_SPEED		0.005f

# define SCOP_MOD_TRANSITION_FREQUENCY	300
# define SCOP_MOD_TRANSITION_SPEED		0.005f

# define SCOP_MODEL_LIMIT				vector3_pack(8, 8, 8)

#endif
