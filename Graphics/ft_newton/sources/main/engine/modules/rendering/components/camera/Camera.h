#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"

class engine::rendering::Camera : public Component
{
public :

	Camera(Object &);
	virtual ~Camera() = default;

	vec3 getPosition() const;

	quat getOrientation() const;
	vec3 getFront() const;
	vec3 getUp() const;
	vec3 getRight() const;

	virtual const mat4 &getProjectionMatrix() const = 0;
	virtual const mat4 &getViewMatrix() const = 0;

protected :

	void initializeInternally() override;

	ComponentFinder<Transformation, Mandatory> _transformationFinder;
};