#pragma once

#include "test/Test.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/ui/components/switch/switchListener/SwitchListener.h"

class test::CollisionVisualiserController final : public Component, public SwitchListener
{
public :

	inline static const std::string typeName = "collision visualiser controller";

	CollisionVisualiserController(Object &object);
	~CollisionVisualiserController() override = default;

protected :

	void initializeInternally() override;

	void onClicked(bool newState) override;

private :

	CollisionVisualiser *_collisionVisualiser;
};
