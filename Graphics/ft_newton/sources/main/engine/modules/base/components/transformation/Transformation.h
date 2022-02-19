#pragma once

#include "engine/modules/base/Base.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/glm/glm.h"
#include "engine/core/scene/object/component/Component.h"

class engine::base::Transformation final : public Component
{
#pragma mark serialization
public :

	inline static const string typeName = "transformation";
	static void deserialize(Transformation &instance, const YAML::Node &node);


#pragma mark events
public :

	Event<> changed;

#pragma mark construction/destruction
public :

	Transformation(Object &object);
	Transformation(Object &object, const vec3 &translation, const vec3 &orientation = vec3(0), const vec3 &scale = vec3(1));

	~Transformation() override = default;

#pragma mark local properties
public :

	const vec3 &getScale() const;
	void setScale(float value);
	void setScale(const vec3 &value);

	const quat &getLocalOrientation() const;

	const vec3 &getLocalPosition() const;

	const mat4 &getScaleMatrix() const;
	const mat4 &getTranslationMatrix() const;
	const mat4 &getRotationMatrix() const;
	const mat4 &getLocalModelMatrix() const;

private :

	vec3 _scale;
	quat _orientation;
	vec3 _position;

#pragma mark global properties
public :

	vec3 getGlobalPosition() const;
	mat4 getGlobalModelMatrix() const;

#pragma mark hieararchy
public :

	Transformation *getParent() const;

	mat4 getOwnHeritageMatrix() const;
	mat4 getParentHeritageMatrix() const;

private :

	Transformation *_parent;

#pragma mark control
public :

	void moveBy(const vec3 &offset);
	void moveTo(const vec3 &newPosition);

	void setOrientation(const quat &value);
	void rotateBy(const quat &rotation);
	void rotateBy(const vec3 &eulerAngles);
	void rotateAround(const vec3 &axis, float angle);

#pragma mark lifecycle
protected :

	void prepareInternally() override;

#pragma mark internal computations
private :

	mat4 _scaleMatrix;
	mat4 _rotationMatrix;
	mat4 _translationMatrix;

	mat4 _heritageMatrix;
	mat4 _modelMatrix;

	void recalculate();
};