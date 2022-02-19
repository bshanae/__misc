#pragma once

#include "engine/core/Core.h"
#include "engine/tools/Tools.h"
#include "engine/modules/base/Base.h"
#include "engine/modules/rendering/Rendering.h"

#include "engine/modules/physics/Physics.h"

namespace engine::physics
{
	class Module;
	class Settings;

	class Collider;
	class PlaneCollider;
	class SphereCollider;
	class BoxCollider;

	class RigidBody;

	class Line;
	class Interval;
	class Plane;
	class Sphere;
	class Box;

	struct Contact;
	class Collision;

	class CollisionDetector;
	class CollisionResolver;
}

namespace engine::physics
{
	// BASE

	using engine::base::Transformation;
	using engine::base::ComponentFinder;

	using engine::base::ComponentImportance::Mandatory;
	using engine::base::ComponentImportance::Optional;

	// RENDERING

	using rendering::Model;
	using rendering::UnlitShader;
	using rendering::CameraFinder;
}