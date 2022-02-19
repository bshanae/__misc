#pragma once

#include "test/Test.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/color/Color.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"
#include "engine/modules/rendering/components/renderer/Renderer.h"
#include "engine/modules/rendering/tools/cameraFinder/CameraFinder.h"

class test::DebugModelRenderer final : public engine::rendering::Renderer
{
public :

	DebugModelRenderer(Object &object);
	DebugModelRenderer(Object &object, const Color &color);
	~DebugModelRenderer() override = default;

protected :

	void initializeInternally() override;
	void prepareInternally() override;

	void render() override;
	bool isClusterRenderer() const override;
	std::string getClusterId() const override;

private :

	std::unique_ptr<UnlitShader> _shader;
	Color _color;

	ComponentFinder<Model, Mandatory> _modelFinder;
	CameraFinder _cameraFinder;

	std::string _clusterId;
};