#pragma once

#include "test/Test.h"

#include "engine/tools/external/glm/glm.h"
#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/rendering/tools/cameraFinder/CameraFinder.h"

class test::Shooter final : public test::Component
{
public :

	inline static const std::string typeName = "shooter";
	static void deserialize(Shooter &instance, const YAML::Node &node);

	Shooter(Object &object);
	~Shooter() override = default;

protected :

	void prepareInternally() override;
	void updateInternally(float timeDelta) override;

	void onDisabled() override;

private :

	std::string _bulletKind;
	glm::vec3 _bulletSize;
	float _bulletMass;
	float _shotForce;

	Object *_bullet;
	FreeCamera *_camera;

	void findCamera();

	void generateBullet();
	void shootBullet();
};
