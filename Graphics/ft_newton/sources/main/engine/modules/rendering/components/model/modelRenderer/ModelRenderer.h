#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"
#include "engine/modules/rendering/components/renderer/Renderer.h"
#include "engine/modules/rendering/tools/cameraFinder/CameraFinder.h"

class engine::rendering::ModelRenderer final : public engine::rendering::Renderer
{
public :

	inline static const string typeName = "model renderer";

	ModelRenderer(Object &object);
	~ModelRenderer() override = default;

protected :

	void initializeInternally() override;
	void prepareInternally() override;

	void render() override;

	bool isClusterRenderer() const override;
	string getClusterId() const override;

private :

	unique_ptr<LitShader> _shader;

	vector<AmbientLight *> _ambientLights;
	vector<PointLight *> _pointLights;

	ComponentFinder<Model, Mandatory> _modelFinder;
	CameraFinder _cameraFinder;
};