#pragma once

#include "engine/core/Core.h"
#include "engine/environment/Environment.h"
#include "engine/tools/Tools.h"
#include "engine/modules/base/Base.h"
#include "engine/modules/rendering/Rendering.h"
#include "engine/modules/physics/Physics.h"
#include "engine/modules/ui/UI.h"

namespace test
{
	class DebugModelRenderer;

	class ColliderCountDisplayer;

	class Manipulator;
	class ManipulatorController;
	class Shooter;
	class ShooterController;
	class ColliderVisualiser;
	class ColliderVisualiserController;
	class CollisionVisualiser;
	class CollisionVisualiserController;
	class FpsDisplayer;
	class DrawCallCountDisplayer;
	class ColliderCountDisplayer;

	class SceneIterator;

	class Launcher;
}

namespace test
{
	// CORE

	using engine::Processor;

	using engine::Scene;

	using engine::Object;
	using engine::Tag;
	using engine::Component;

	namespace serialization = engine::serialization;

	// ENVIRONMENT

	using engine::Input;
	using engine::Environment;

	using engine::RenderingOptions;

	// TOOLS

	using engine::vec2;
	using engine::vec3;
	using engine::vec4;
	using engine::mat4;

	using engine::Listener;

	using engine::Debug;

	using engine::Color;

	// BASE MODULE

	using engine::base::Transformation;

	template <typename T, engine::base::ComponentImportance importance>
	using ComponentFinder = engine::base::ComponentFinder<T, importance>;

	using engine::base::ComponentImportance::Mandatory;
	using engine::base::ComponentImportance::Optional;

	// RENDERING MODULE

	using RenderingModule = engine::rendering::Module;
	using RenderingLayer = engine::rendering::Layer;

	using engine::rendering::FreeCamera;
	using engine::rendering::CameraFinder;

	using engine::rendering::AmbientLight;
	using engine::rendering::PointLight;

	using engine::rendering::UnlitShader;
	using engine::rendering::LitShader;

	using engine::rendering::Renderer;

	using engine::rendering::Model;
	using engine::rendering::ModelRenderer;

	// PHYSICS MODULE

	using PhysicsModule = engine::physics::Module;

	using engine::physics::Collider;
	using engine::physics::SphereCollider;
	using engine::physics::PlaneCollider;
	using engine::physics::BoxCollider;

	using engine::physics::RigidBody;

	// UI MODULE

	using engine::ui::Text;
	using engine::ui::TextRenderer;

	using engine::ui::SwitchListener;
}