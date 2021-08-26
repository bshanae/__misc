#version 330 core

struct ambient_light
{
	vec3 color;
	float intensity;
};

struct point_light
{
	vec3 position;
	vec3 color;
	float intensity;
};

uniform int number_of_ambient_lights;
uniform ambient_light ambient_lights[10];

uniform int number_of_point_lights;
uniform point_light point_lights[10];

uniform vec3 material_color;

in vec3 pass_position;
in vec3 pass_normal;

out vec4 out_color;

vec3 calculate_ambient_light(ambient_light light)
{
	return material_color * light.color * light.intensity;
}

vec3 calculate_point_light(point_light light)
{
	vec3 light_direction = normalize(light.position - pass_position);
	float intensity = max(dot(pass_normal, light_direction), 0.0);

	return material_color * light.color * light.intensity * intensity;
}

void main()
{
	vec3 finalColor = vec3(0, 0, 0);

	for (int i = 0; i < number_of_ambient_lights; i++)
		finalColor += calculate_ambient_light(ambient_lights[i]);

	for (int i = 0; i < number_of_point_lights; i++)
		finalColor += calculate_point_light(point_lights[i]);

	out_color = vec4(finalColor, 1);
}