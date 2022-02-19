#pragma once

#include "test/Test.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/ui/components/switch/switchListener/SwitchListener.h"

class test::ColliderVisualiserController final : public Component, public SwitchListener
{
public :

	inline static const std::string typeName = "collider visualiser controller";

	ColliderVisualiserController(Object &object);
	~ColliderVisualiserController() override = default;

protected :

	void onClicked(bool newState) override;
};
