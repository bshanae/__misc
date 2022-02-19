#include "TextRenderer.h"

#include "engine/core/settings/Settings.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/ui/components/text/textShader/LabelShader.h"
#include "engine/modules/ui/tools/font/Font.h"
#include "engine/modules/ui/tools/font/symbol/Symbol.h"

using namespace engine::ui;

TextRenderer::TextRenderer(Object &object) : Renderer(object, RenderingLayer::UI), _textFinder(*this), _transformationFinder(*this)
{}

void TextRenderer::initializeInternally()
{
	_shader = make_unique<LabelShader>();
	if (not _shader->isValid())
	{
		Debug::logError("TextRenderer", "Shader is not valid.");
		markBad();
		return;
	}

	const auto width = (float)engine::Settings::getWindowSize().x;
	const auto height = (float)engine::Settings::getWindowSize().y;

	_shader->use(true);
	_shader->setProjection(ortho(0.0f, width, 0.0f, height));
	_shader->use(false);
}

void TextRenderer::render()
{
	_shader->use(true);
	_shader->setTextColor(_textFinder().getFontColor());

	auto xOffset = 0.f;
	for (auto character : _textFinder().getText())
	{
		auto *symbol = _textFinder().getFont()->getSymbol(character);
		if (symbol == nullptr)
			continue;

		xOffset += symbol->getBearing().x * getScale();

		if (symbol->getTexture() != 0)
		{
			symbol->bind(true);

			_shader->setTransformation(calculateSymbolTransformationMatrix(xOffset));

			glBindTexture(GL_TEXTURE_2D, symbol->getTexture());
			glDrawArrays(GL_TRIANGLES, 0, 6);

			symbol->bind(false);
		}

		xOffset += (symbol->getAdvance() >> 6) * getScale();
	}

	_shader->use(false);
}

float TextRenderer::getScale() const
{
	return _textFinder().getFontHeight() / _textFinder().getFont()->getHeight();
}

engine::mat4 TextRenderer::calculateSymbolTransformationMatrix(float xOffset) const
{
	return _transformationFinder().getParentHeritageMatrix() *
		   _transformationFinder().getTranslationMatrix() *
		   translate(vec3(xOffset, 0, 0)) *
		   scale(vec3(getScale()));
}