#pragma once

#include "engine/core/Core.h"
#include "engine/environment/Environment.h"
#include "engine/modules/base/Base.h"
#include "engine/modules/rendering/Rendering.h"

namespace engine::rendering
{
	class Module;
	class Settings;

	enum class Layer;

	class Camera;
	class FreeCamera;
	class CameraFinder;

	class AmbientLight;
	class PointLight;

	class LitShader;
	class UnlitShader;

	class Model;
	class ModelParser;
	class ModelStorage;
	class ModelRenderer;

	class Renderer;

	class Mesh;
	class Vertex;

	class Material;
}

namespace engine::rendering
{
	using Transformation = engine::base::Transformation;

	template <typename T, engine::base::ComponentImportance importance>
	using ComponentFinder = engine::base::ComponentFinder<T, importance>;

	using engine::base::ComponentImportance::Mandatory;
	using engine::base::ComponentImportance::Optional;
}