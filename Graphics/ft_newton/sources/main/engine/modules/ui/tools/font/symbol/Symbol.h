#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/tools/external/glm/glm.h"

class engine::ui::Symbol final
{
public :

	Symbol(unsigned texture, const uvec2 &size, const uvec2 &bearing, unsigned advance);
	~Symbol();

	inline int getTexture() const
	{
		return _texture;
	}

	inline const uvec2 &getBearing() const
	{
		return _bearing;
	}

	inline const uvec2 &getSize() const
	{
		return _size;
	}

	inline unsigned getAdvance() const
	{
		return _advance;
	}

	inline void bind(bool state) const
	{
		bindVertexArray(state);
	}

private :

	const unsigned _texture;
	const uvec2 _size;
	const uvec2 _bearing;
	const unsigned _advance;

	unsigned _vertexArray;
	unsigned _vertexBuffer;
	unsigned _textureCoordinateBuffer;

	void buildVertexArray();
	void buildVertexBuffer();
	void buildTextureCoordinateBuffer();

	void bindVertexArray(bool state) const;
};