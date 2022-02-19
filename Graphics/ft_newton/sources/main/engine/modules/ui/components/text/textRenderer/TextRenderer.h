#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/core/scene/Scene.h"
#include "engine/modules/rendering/tools/layer/Layer.h"

#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"
#include "engine/modules/rendering/components/renderer/Renderer.h"
#include "engine/modules/ui/components/text/Text.h"

class engine::ui::TextRenderer final : public Renderer
{
public :

	inline static const string typeName = "text renderer";

	TextRenderer(Object &object);
	~TextRenderer() override = default;

protected :

	void initializeInternally() override;

	void render() override;

private :

	ComponentFinder<Text, Mandatory> _textFinder;
	ComponentFinder<Transformation, Mandatory> _transformationFinder;
	unique_ptr<LabelShader> _shader;

	float getScale() const;
	mat4 calculateSymbolTransformationMatrix(float xOffset) const;
};