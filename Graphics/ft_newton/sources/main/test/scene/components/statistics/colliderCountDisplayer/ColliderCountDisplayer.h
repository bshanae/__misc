#pragma once

#include "test/Test.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/color/Color.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"

class test::ColliderCountDisplayer final : public Component
{
public :

	inline static const std::string typeName = "collider count displayer";

	ColliderCountDisplayer(Object &object);
	~ColliderCountDisplayer() override = default;

protected :

	void updateInternally(float timeDelta) override;

private :

	ComponentFinder<Text, Mandatory> _textFinder;
};