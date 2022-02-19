#pragma once

#include "game/Game.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"

class game::Page : public Component
{
public :

	inline static const std::string typeName = "page";
	static void deserialize(Page &instance, const YAML::Node &node);

	Page(Object &object);
	~Page() override = default;

	inline const std::string &getName() const
	{
		return _ownName;
	}

	inline const std::string &getParentName() const
	{
		return _parentName;
	}

	virtual void activate();
	virtual void deactivate();

private :

	std::string _ownName;
	std::string _parentName;
};
