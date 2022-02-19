#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/tools/external/FreeType2.h"
#include "engine/tools/templates/LazyStaticClass.h"
#include "engine/tools/debug/Debug.h"
#include "engine/modules/ui/tools/font/Font.h"
#include "engine/modules/ui/tools/font/symbol/Symbol.h"

class engine::ui::FontLibrary final : LazyStaticClass<FontLibrary>
{
	friend class LazyStaticClass<FontLibrary>;

public :

	FontLibrary() = delete;
	~FontLibrary() = delete;

	static inline FT_Library &getLibrary()
	{
		initializeIfNeeded();
		return _library;
	};

	static void loadFont(const string &fontName, float height);

	static Font *getFont(const string &fontName);

private:

	static inline FT_Library _library;
	static inline map<string, unique_ptr<Font>> _fonts;

	static void initialize();
};