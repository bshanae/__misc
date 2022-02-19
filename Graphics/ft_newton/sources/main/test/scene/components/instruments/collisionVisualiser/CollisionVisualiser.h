#pragma once

#include "test/Test.h"

#include "engine/tools/external/std/vector.h"
#include "engine/tools/external/glm/glm.h"
#include "engine/core/scene/object/component/Component.h"

class test::CollisionVisualiser final : public Component
{
public :

	inline static const std::string typeName = "collision visualiser";

	CollisionVisualiser(Object &);
	~CollisionVisualiser() = default;

protected :

	void prepareInternally() override;
	void updateInternally(float timeDelta) override;
	void onDisabled() override;

private :

	std::vector<Object *> _spheres;

	void generateSphere();
};
