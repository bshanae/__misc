#version 400 core

#define SCOP_MOD_RGB		0
#define SCOP_MOD_RANDOM		1
#define SCOP_MOD_MATERIAL	2
#define SCOP_MOD_TEXTURE	3

///////////////////////////////////////////////////////////////////////////////
//							IN-OUT
///////////////////////////////////////////////////////////////////////////////

in vec3						pass_original_position;
in vec3						pass_transformed_position;
in vec3						pass_normal;
in vec3						pass_rgb_color;
in vec3						pass_random_color;
in vec2						pass_UV;

out vec4					out_color;

uniform vec3				uniform_camera_position;

uniform int					uniform_mod_from;
uniform int					uniform_mod_to;
uniform float				uniform_mod_transition;

uniform struct
{
	bool					use_texture;
	sampler2D				texture;
	vec3					ambient;
	vec3					diffuse;
	vec3					specular;
	float					specular_exponent;
	float 					alpha;
}							uniform_material;

uniform sampler2D			uniform_texture;

///////////////////////////////////////////////////////////////////////////////
//							ADDITIONAL
///////////////////////////////////////////////////////////////////////////////

vec3						light_position = vec3(0, 0, 20);
vec3						light_color = vec3(1, 1, 1);

vec4						material_color()
{
	vec3					ambient_final = light_color * uniform_material.ambient;

	vec3					normal = normalize(pass_normal);
	vec3					light_direction = normalize(light_position - pass_transformed_position);
	float					diffuse = max(dot(normal, light_direction), 0.2);
	vec3					diffuse_final = light_color * diffuse * (uniform_material.use_texture ? texture(uniform_material.texture, pass_UV).rgb : uniform_material.diffuse);

	vec3					view_direction = normalize(uniform_camera_position - pass_transformed_position);
	vec3					reflection_direction = reflect(-light_direction, normal);
	float					specular =
		pow(max(dot(view_direction, reflection_direction), 0.0), 1. + uniform_material.specular_exponent);
	vec3					specular_final = light_color * (specular * uniform_material.specular);

	return (vec4(ambient_final + diffuse_final + specular_final, uniform_material.alpha));
}

vec4						mod_color(int mod)
{
	if (mod == SCOP_MOD_RGB)
		return (vec4(pass_rgb_color, 1));
	else if (mod == SCOP_MOD_RANDOM)
		return (vec4(pass_random_color, 1));
	else if (mod == SCOP_MOD_MATERIAL)
		return (material_color());
	else if (mod == SCOP_MOD_TEXTURE)
		return (texture(uniform_texture, pass_UV));
	return (vec4(0, 0, 0, 1));
}

///////////////////////////////////////////////////////////////////////////////
//							MAIN
///////////////////////////////////////////////////////////////////////////////

void						main()
{
	out_color =
		mod_color(uniform_mod_from) * (1.f - uniform_mod_transition) +
		mod_color(uniform_mod_to) * uniform_mod_transition;
}