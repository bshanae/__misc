#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/tools/color/Color.h"
#include "engine/modules/ui/components/control/Control.h"

class engine::ui::Background : public Control
{
public :

	inline static const string typeName = "background";
	static void deserialize(Background &instance, const YAML::Node &node);

	Background(Object &object);
	Background(Object &object, const Color &color);

	~Background() override = default;

	inline const Color &getColor() const
	{
		return _color;
	}

	void setColor(const Color &value)
	{
		_color = value;
	}

private :

	Color _color;
};
