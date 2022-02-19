#include "FontLibrary.h"

using namespace engine::ui;

void FontLibrary::loadFont(const string &fontName, float height)
{
	initializeIfNeeded();

	if (_fonts.find(fontName) == _fonts.end())
		_fonts[fontName] = make_unique<Font>(fontName, height);
};

Font *FontLibrary::getFont(const string &fontName)
{
	assumeInitialized();

	if (auto iterator = _fonts.find(fontName); iterator != _fonts.end())
	{
		return iterator->second.get();
	}
	else
	{
		Debug::logWarning("FontLibrary", "Font '" + fontName + "' not found");
		return nullptr;
	}
}

void FontLibrary::initialize()
{
	if (FT_Init_FreeType(&_library))
		Debug::logError("FontLibrary", "Couldn't init FreeType library");
}