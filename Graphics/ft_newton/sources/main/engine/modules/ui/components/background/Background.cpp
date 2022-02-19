#include "Background.h"

#include "engine/core/scene/object/Object.h"

using namespace engine::ui;

void Background::deserialize(Background &instance,  const YAML::Node &node)
{
	instance._color = node["color"].as<Color>();
}

Background::Background(Object &object) : Control(object)
{}

Background::Background(Object &object, const Color &color) : Control(object), _color(color)
{}
