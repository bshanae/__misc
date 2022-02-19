#version 330 core

uniform mat4 projection;
uniform mat4 view;

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in mat4 in_transformation;

out vec3 pass_position;
out vec3 pass_normal;

void main()
{
    vec4 transformed_position = in_transformation * vec4(in_position, 1.0);
    vec4 transformed_normal = normalize(in_transformation * vec4(in_normal, 0.0));

    pass_position = transformed_position.xyz;
    pass_normal = transformed_normal.xyz;

    gl_Position = projection * view * transformed_position;
}