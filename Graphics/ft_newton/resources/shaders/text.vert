#version 400 core

layout (location = 0) in vec2 in_position;
layout (location = 1) in vec2 in_texture_coordinates;

out vec2 pass_texture_coordinates;

uniform mat4 transformation;
uniform mat4 projection;

void main()
{
    gl_Position = projection * transformation * vec4(in_position, 1.0, 1.0);
    pass_texture_coordinates = in_texture_coordinates;
}