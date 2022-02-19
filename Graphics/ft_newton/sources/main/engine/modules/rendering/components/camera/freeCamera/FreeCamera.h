#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/tools/external/glm/glm.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"
#include "engine/modules/rendering/components/camera/Camera.h"

class engine::rendering::FreeCamera final : public Camera
{
public :

	inline static const string typeName = "free camera";
	static void deserialize(FreeCamera &instance, const YAML::Node &node);

	FreeCamera(Object &object);
	~FreeCamera() override = default;

	const mat4 &getProjectionMatrix() const override
	{
		return _projection;
	}

	const mat4 &getViewMatrix() const override
	{
		return _view;
	}

protected :

	void initializeInternally() override;
	void updateInternally(float timeDelta) override;

private :

	float _movementSpeed;
	float _rotationSpeed;
	float _fov;
	float _nearPlane;
	float _farPlane;

	mat4 _projection;
	mat4 _view;

	bool processRotationInput(float timeDelta);
	bool processMovementInput(float timeDelta);

	void recalculate();
};