#version 400 core

in vec2 pass_texture_coordinates;
out vec4 out_color;

uniform sampler2D texture_id;
uniform vec4 text_color;

void main()
{
    out_color = text_color * vec4(1.0, 1.0, 1.0, texture(texture_id, pass_texture_coordinates).r);
}