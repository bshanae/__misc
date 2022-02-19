#include "Font.h"

#include "engine/modules/ui/tools/font/symbol/Symbol.h"
#include "engine/modules/ui/tools/font/fontLibrary/FontLibrary.h"

using namespace engine::ui;

Font::Font(const string &fontName, float height) : _name(fontName + ".ttf"), _height(height)
{
	loadFontFace();
	loadSymbols();
}

Font::~Font()
{
	FT_Done_Face(_face);
}

Symbol *Font::getSymbol(char character) const
{
	if (auto iterator = _symbols.find(character); iterator != _symbols.end())
	{
		return iterator->second.get();
	}
	else
	{
		Debug::logWarning("Font", "Symbol '" + string(1, character) + "' not found");
		return nullptr;
	}
}

void Font::loadFontFace()
{
	if (FT_New_Face(FontLibrary::getLibrary(), ("./resources/fonts/" + _name).c_str(), 0, &_face))
		Debug::logError("Font", "Failed to load font of file '" + _name + "'");
}

void Font::loadSymbols()
{
	FT_Set_Pixel_Sizes(_face, 0, _height);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (char character = 32u; character <= 126u; character++)
	{
		if (FT_Load_Char(_face, character, FT_LOAD_RENDER) != 0)
		{
			Debug::logWarning("Font", "Failed to load glyph '" + string(1, character) + "'");
			continue;
		}

		const auto texture = _face->glyph->bitmap.width > 0 ? generateTexture(_face) : 0;
		const auto size = uvec2(_face->glyph->bitmap.width, _face->glyph->bitmap.rows);
		const auto bearing = uvec2(_face->glyph->bitmap_left, _face->glyph->bitmap_top);
		const auto advance = _face->glyph->advance.x;

		_symbols[character] = make_unique<Symbol>(texture, size, bearing, advance);
	}
}

unsigned Font::generateTexture(FT_Face face)
{
	unsigned texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RED,
		face->glyph->bitmap.width,
		face->glyph->bitmap.rows,
		0,
		GL_RED,
		GL_UNSIGNED_BYTE,
		face->glyph->bitmap.buffer
	);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);

	return texture;
}