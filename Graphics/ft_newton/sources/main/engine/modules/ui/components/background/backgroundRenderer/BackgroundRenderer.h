#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/external/std/pointers.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"
#include "engine/modules/rendering/components/renderer/Renderer.h"
#include "engine/modules/rendering/tools/cameraFinder/CameraFinder.h"

class engine::ui::BackgroundRenderer : public Renderer
{
public :

	inline static const string typeName = "background renderer";

	BackgroundRenderer(Object &object);
	~BackgroundRenderer() override = default;

protected :

	void initializeInternally() override;

	void render() override;

private :

	ComponentFinder<Background, Mandatory> _backgroundFinder;
	ComponentFinder<Transformation, Mandatory> _transformationFinder;

	unique_ptr<Mesh> _mesh;
	shared_ptr<Material> _material;
	unique_ptr<UnlitShader> _shader;

	void initializeShader();
	void initializeMesh();
};