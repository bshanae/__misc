#pragma once

#include "test/Test.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/ui/components/switch/switchListener/SwitchListener.h"

class test::ManipulatorController final : public Component, public SwitchListener
{
public :

	inline static const std::string typeName = "manipulator controller";

	ManipulatorController(Object &object);
	~ManipulatorController() override = default;

protected :

	void initializeInternally() override;

	void onClicked(bool newState) override;

private :

	Manipulator *_manipulator;
};
