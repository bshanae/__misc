#include "Material.h"

using namespace Engine;

Color Material::getColor() const
{
	return _color;
}

void Material::setColor(const Color &color)
{
	_color = color;
}

std::shared_ptr<Texture> Material::getTexture() const
{
	return _texture;
}

void Material::setTexture(const std::shared_ptr<Texture> &texture)
{
	_texture = texture;
}