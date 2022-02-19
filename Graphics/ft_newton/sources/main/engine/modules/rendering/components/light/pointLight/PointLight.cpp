#include "PointLight.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

using namespace engine::rendering;

void PointLight::deserialize(PointLight &instance, const YAML::Node &node)
{
	instance.setPosition(node["position"].as<vec3>());
	instance.setColor(node["color"].as<Color>(Color::white));
	instance.setIntensity(node["intensity"].as<float>(0.1f));
}

PointLight::PointLight(Object &object) : Component(object)
{
	_position = vec3();
	_color = Color::white;
	_intensity = 1.f;
}