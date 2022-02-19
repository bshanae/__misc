#pragma once

#include "test/Test.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/rendering/tools/cameraFinder/CameraFinder.h"
#include "test/scene/tools/sceneIterator/SceneIterator.h"

class test::Manipulator : public Component
{
public :

	inline static const std::string typeName = "manipulator";
	static void deserialize(Manipulator &instance, const YAML::Node &node);

	Manipulator(Object &object);
	~Manipulator() override = default;

protected :

	void initializeInternally() override;
	void prepareInternally() override;
	void updateInternally(float timeDelta) override;

	void onEnabled() override;
	void onDisabled() override;

private :

	float _impulseFactor;

	CameraFinder _cameraFinder;
	SceneIterator _sceneIterator;
	Object *_hint;

	void generateHint();
	void updateHint();

	void processTargetChange();
	void processMovement(float timeDelta);

	static bool objectFilter(Object &object);
};
