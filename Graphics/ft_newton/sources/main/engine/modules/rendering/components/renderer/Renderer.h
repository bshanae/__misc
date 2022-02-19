#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/environment/renderingOptions/RenderingOptions.h"

class engine::rendering::Renderer : public engine::Component
{
public :

	Renderer(Object &object, Layer layer) : Component(object), _layer(layer)
	{
		_desiredRenderingOptions = RenderingOptions::FaceCulling;
	}

	~Renderer() override = default;

	inline Layer getLayer() const
	{
		return _layer;
	}

	inline RenderingOptions getDesiredRenderingOptions() const
	{
		return _desiredRenderingOptions;
	}

	virtual bool isClusterRenderer() const
	{
		return false;
	}

	virtual string getClusterId() const
	{
		return "";
	}

	virtual void render() = 0;

protected :

	RenderingOptions _desiredRenderingOptions;

private :

	const Layer _layer;
};