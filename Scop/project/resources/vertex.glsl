#version 330 core

layout (location = 0) in vec3	in_position;
layout (location = 1) in vec2	in_texture;
layout (location = 2) in vec3	in_normal;
layout (location = 3) in vec3	in_color;

out vec3						pass_position;
out vec3						pass_normal;
out vec3						pass_color_random;
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

	pass_position = transformed_position;
	pass_UV = in_texture;
	pass_normal = transformed_normal;
	pass_color_random = in_color;

	gl_Position = uniform_projection * uniform_view * vec4(transformed_position, 1);
}