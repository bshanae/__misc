#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/color/Color.h"
#include "engine/modules/ui/components/control/Control.h"

class engine::ui::Text : public Control
{
public :

	inline static const string typeName = "text";
	static void deserialize(Text &instance, const YAML::Node &node);

	Text(Object &object);
	Text(Object &object, const string &fontName, float fontHeight, const Color &fontColor, const string &value = "");

	~Text() override = default;

	inline void setText(const string &value)
	{
		_text = value;
	}

	inline const string &getText() const
	{
		return _text;
	}

	inline const Color &getFontColor() const
	{
		return _fontColor;
	}

	inline void setFontColor(const Color &value)
	{
		_fontColor = value;
	}

	inline void setHeight(float value)
	{
		_fontHeight = value;
	}

	inline float getFontHeight() const
	{
		return _fontHeight;
	}

	void setFont(const string &fontName);

	inline Font *getFont() const
	{
		return _font;
	}

protected :

	void initializeInternally() override;

private :

	Color _fontColor;
	float _fontHeight;
	string _fontName;
	string _text;

	Font *_font;
};