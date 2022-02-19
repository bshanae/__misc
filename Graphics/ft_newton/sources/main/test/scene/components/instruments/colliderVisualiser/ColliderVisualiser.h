#pragma once

#include "test/Test.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/color/Color.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"
#include "engine/modules/rendering/components/renderer/Renderer.h"
#include "engine/modules/rendering/tools/cameraFinder/CameraFinder.h"

class test::ColliderVisualiser final : public Renderer
{
public :

	ColliderVisualiser(Object &object, Collider &collider);
	~ColliderVisualiser() override = default;

protected :

	void initializeInternally() override;
	void prepareInternally() override;

	void render() override;

private :

	CameraFinder _cameraFinder;

	std::unique_ptr<UnlitShader> _shader;
	Collider *_collider;
	Model *_model;
	mat4 _modelTransformation;

	static inline Color NormalColor = { 0.0, 1.0, 0.0, 1 };
	static inline Color ActiveColor = { 1.0, 0.0, 0.0, 1 };

	void loadModel();
	void computeTransformation();
};