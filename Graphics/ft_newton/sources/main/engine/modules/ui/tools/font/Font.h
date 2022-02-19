#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/tools/debug/Debug.h"
#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/std/map.h"
#include "engine/tools/external/OpenGL.h"
#include "engine/tools/external/FreeType2.h"

class engine::ui::Font final
{
public :

	Font(const string &fontName, float height);
	~Font();

	inline float getHeight() const
	{
		return _height;
	}

	Symbol *getSymbol(char character) const;

private :

	const string _name;
	const float _height;

	FT_Face _face;
	map<char, unique_ptr<Symbol>> _symbols;

	void loadFontFace();
	void loadSymbols();

	static unsigned generateTexture(FT_Face face);
};