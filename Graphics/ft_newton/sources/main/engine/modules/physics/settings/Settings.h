#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/set.h"
#include "engine/tools/external/glm/glm.h"

class engine::physics::Settings
{
	friend class Module;

public :

	Settings() = delete;
	~Settings() = delete;

	inline static float getLinearVelocityDamping()
	{
		return _linearVelocityDamping;
	}

	inline static float getAngularVelocityDamping()
	{
		return _angularVelocityDamping;
	}

	inline static vec3 getGravityAcceleration()
	{
		return _gravityAcceleration;
	}

private :

	static inline float _linearVelocityDamping;
	static inline float _angularVelocityDamping;
	static inline vec3 _gravityAcceleration;

	static void load();
};