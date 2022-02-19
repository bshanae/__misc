#include "AmbientLight.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

using namespace engine::rendering;

void AmbientLight::deserialize(AmbientLight &instance, const YAML::Node &node)
{
	instance.setColor(node["color"].as<Color>(Color::white));
	instance.setIntensity(node["intensity"].as<float>(0.1f));
}

AmbientLight::AmbientLight(Object &object) : Component(object)
{
	_color = Color::white;
	_intensity = 0.1f;
}