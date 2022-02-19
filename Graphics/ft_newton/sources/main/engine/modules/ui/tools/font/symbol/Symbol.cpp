#include "Symbol.h"

#include "engine/tools/external/std/array.h"
#include "engine/tools/external/OpenGL.h"

using namespace engine::ui;

Symbol::Symbol(unsigned texture, const uvec2 &size, const uvec2 &bearing, unsigned advance) :
	_texture(texture), _size(size), _bearing(bearing), _advance(advance)
{
	buildVertexArray();
	bindVertexArray(true);

	buildVertexBuffer();
	buildTextureCoordinateBuffer();

	bindVertexArray(false);
}

Symbol::~Symbol()
{
	glDeleteVertexArrays(1, &_vertexArray);

	glDeleteBuffers(1, &_vertexBuffer);
	glDeleteBuffers(1, &_textureCoordinateBuffer);
}

void Symbol::buildVertexArray()
{
	glGenVertexArrays(1, &_vertexArray);
}

void Symbol::buildVertexBuffer()
{
	const auto x = _bearing.x;
	const auto y = (_size.y - _bearing.y) * -1.f;

	const auto w = _size.x;
	const auto h = _size.y;

	const auto vertices = array<vec2, 6>{
		vec2(x + 0, y + h),
		vec2(x + 0, y + 0),
		vec2(x + w, y + 0),
		vec2(x + 0, y + h),
		vec2(x + w, y + 0),
		vec2(x + w, y + h)
	};

	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vec2), vertices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Symbol::buildTextureCoordinateBuffer()
{
	static const auto textureCoordinates = array <vec2, 6>{
		vec2(0.0f, 0.0f),
		vec2(0.0f, 1.0f),
		vec2(1.0f, 1.0f),
		vec2(0.0f, 0.0f),
		vec2(1.0f, 1.0f),
		vec2(1.0f, 0.0f)
	};

	glGenBuffers(1, &_textureCoordinateBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _textureCoordinateBuffer);

	glBufferData(GL_ARRAY_BUFFER, textureCoordinates.size() * sizeof(vec2), textureCoordinates.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Symbol::bindVertexArray(bool state) const
{
	glBindVertexArray(state ? _vertexArray : 0);
}