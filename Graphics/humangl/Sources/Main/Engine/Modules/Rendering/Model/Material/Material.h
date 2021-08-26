#pragma once

#include <memory>

#include "Color.h"

namespace Engine
{
	class Texture;
	class Material;
}

class Engine::Material final
{
public :

	Color getColor() const;
	void setColor(const Color &color);

	std::shared_ptr<Texture> getTexture() const;
	void setTexture(const std::shared_ptr<Texture> &texture);

private :

	std::shared_ptr<Texture> _texture;
	Color _color;
};