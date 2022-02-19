#include "CameraFinder.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/Object.h"

using namespace engine::rendering;

CameraFinder::CameraFinder(Scene &scene)
{
	if (scene.isLaunched())
	{
		findCamera(scene);
	}
	else
	{
		subscribe(
			scene.launched,
			[this, &scene]() { findCamera(scene); }
		);
	}
}

Camera &CameraFinder::operator () ()
{
	return *_camera;
}

void CameraFinder::findCamera(Scene &scene)
{
	_camera = &scene.selectObjectByTag("camera").selectComponent<Camera>();
}