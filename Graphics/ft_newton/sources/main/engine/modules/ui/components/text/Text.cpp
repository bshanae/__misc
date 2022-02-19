#include "Text.h"

#include "engine/core/scene/object/Object.h"
#include "engine/modules/ui/tools/font/fontLibrary/FontLibrary.h"

using namespace engine::ui;

void Text::deserialize(Text &instance, const YAML::Node &node)
{
	instance._fontName = node["font name"].as<string>("arial");
	instance._fontHeight = node["font height"].as<float>();
	instance._fontColor = node["font color"].as<Color>(Color::white);
	instance._text = node["text"].as<string>("empty");
}

Text::Text(Object &object) : Control(object)
{}

Text::Text(Object &object, const string &fontName, float fontHeight, const Color &fontColor, const string &value) :
	Control(object), _fontName(fontName), _fontHeight(fontHeight), _fontColor(fontColor), _text(value)
{}

void Text::setFont(const string &fontName)
{
	_fontName = fontName;

	if (isPrepared())
		_font = FontLibrary::getFont(_fontName);
}

void Text::initializeInternally()
{
	_font = FontLibrary::getFont(_fontName);
}