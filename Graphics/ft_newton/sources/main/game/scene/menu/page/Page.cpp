#include "Page.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

using namespace game;

void Page::deserialize(Page &instance, const YAML::Node &node)
{
	instance._ownName = node["own name"].as<std::string>();
	instance._parentName = node["parent name"].as<std::string>("");
}

Page::Page(Object &object) : Component(object)
{}

void Page::activate()
{
	getObject().enable();
}

void Page::deactivate()
{
	getObject().disable();
}