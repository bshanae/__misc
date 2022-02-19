#version 330 core

uniform mat4 projection;
uniform mat4 view;

layout (location = 0) in vec3 in_position;
layout (location = 2) in mat4 in_transformation;

void main()
{
    gl_Position = projection * view * in_transformation * vec4(in_position, 1.0);
}