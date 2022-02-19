#pragma once

#include "test/Test.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/ui/components/switch/switchListener/SwitchListener.h"

class test::ShooterController final : public Component, public SwitchListener
{
public :

	inline static const std::string typeName = "shooter controller";

	ShooterController(Object &object);
	~ShooterController() override = default;

protected :

	void initializeInternally() override;

	void onClicked(bool newState) override;

private :

	Shooter *_shooter;
};
