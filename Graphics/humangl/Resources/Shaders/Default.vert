#version 330 core

#define NUMBER_OF_BONES 200

uniform mat4 projection;
uniform mat4 view;
uniform mat4 transformation;
uniform mat4 bones_mesh[NUMBER_OF_BONES];

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec3 in_texture_coordinate;
layout (location = 3) in ivec4 in_bones_ids;
layout (location = 4) in vec4 in_bones_weights;

out vec3 pass_position;
out vec3 pass_normal;

void main()
{
    mat4 bone_transformation = bones_mesh[in_bones_ids[0]] * in_bones_weights[0];

    bone_transformation += bones_mesh[in_bones_ids[1]] * in_bones_weights[1];
    bone_transformation += bones_mesh[in_bones_ids[2]] * in_bones_weights[2];
    bone_transformation += bones_mesh[in_bones_ids[3]] * in_bones_weights[3];

    vec4 transformed_position = transformation * bone_transformation * vec4(in_position, 1.0);
    vec4 transformed_normal = transformation * bone_transformation * vec4(in_normal, 0.0);

    pass_position = transformed_position.xyz;
    pass_normal = transformed_normal.xyz;

    gl_Position = projection * view * transformed_position;
}