#pragma once

#include "engine/core/Core.h"
#include "engine/environment/Environment.h"
#include "engine/modules/base/Base.h"
#include "engine/modules/physics/Physics.h"
#include "engine/modules/rendering/Rendering.h"
#include "engine/modules/ui/UI.h"

namespace engine::ui
{
	class Module;
	class Settings;

	class Control;

	class Text;
	class TextRenderer;
	class LabelShader;

	class Button;
	class ButtonListener;
	class Switch;
	class SwitchListener;

	class Background;
	class BackgroundRenderer;

	class FontLibrary;
	class Symbol;
	class Font;
}

namespace engine::ui
{
	using engine::Environment;
	using engine::Input;

	using engine::base::ComponentImportance::Mandatory;
	using engine::base::ComponentImportance::Optional;

	using engine::base::Transformation;
	using engine::base::ComponentFinder;

	using engine::rendering::CameraFinder;
	using engine::rendering::Mesh;
	using engine::rendering::Material;
	using engine::rendering::Vertex;
	using engine::rendering::Renderer;
	using engine::rendering::UnlitShader;
	using RenderingLayer = engine::rendering::Layer;

	using engine::physics::Collider;
	using engine::physics::RigidBody;
}