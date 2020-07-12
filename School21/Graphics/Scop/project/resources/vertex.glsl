#version 330 core

layout (location = 0) in vec3	in_position;
layout (location = 1) in vec2	in_texture;
layout (location = 2) in vec3	in_normal;
layout (location = 3) in vec3	in_rgb_color;
layout (location = 4) in vec3	in_random_color;

out vec3						pass_original_position;
out vec3						pass_transformed_position;
out vec3						pass_normal;
out vec3						pass_rgb_color;
out vec3						pass_random_color;
out vec2						pass_UV;

uniform vec3					uniform_single_color;
uniform mat4					uniform_projection;
uniform mat4					uniform_view;
uniform mat4					uniform_transformation;

void							main()
{
	vec3						transformed_position;
	vec3						transformed_normal;

	transformed_position = vec3(uniform_transformation * vec4(in_position, 1));
	transformed_normal = normalize(vec3(uniform_transformation * vec4(in_normal, 0)));

	pass_original_position = in_position;
	pass_transformed_position = transformed_position;
	pass_UV = in_texture;
	pass_normal = transformed_normal;
	pass_rgb_color = in_rgb_color;
	pass_random_color = in_random_color;

	gl_Position = uniform_projection * uniform_view * vec4(transformed_position, 1);
}