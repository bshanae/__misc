#include "Settings.h"

#include "engine/core/settings/Settings.h"
#include "engine/tools/constants/Constants.h"
#include "engine/tools/debug/Debug.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

using namespace engine::physics;

void Settings::load()
{
	try
	{
		const auto root = YAML::LoadFile(engine::Settings::source);
		const auto physicsNode = root["physics"];

		_linearVelocityDamping = physicsNode["linear velocity damping"].as<float>();
		_angularVelocityDamping = physicsNode["angular velocity damping"].as<float>();
		_gravityAcceleration = physicsNode["gravity acceleration"].as<vec3>();
	}
	catch (const YAML::Exception &exception)
	{
		Debug::invokeFatalError("physics::Settings", "Can't parse settings");
	}
}