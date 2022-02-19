#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/modules/rendering/components/camera/Camera.h"
#include "engine/tools/templates/eventSystem/listener/Listener.h"

class engine::rendering::CameraFinder final : public Listener
{
public :

	CameraFinder(Scene &scene);
	~CameraFinder() = default;

	Camera &operator () ();

private :

	Camera *_camera;

	void findCamera(Scene &scene);
};