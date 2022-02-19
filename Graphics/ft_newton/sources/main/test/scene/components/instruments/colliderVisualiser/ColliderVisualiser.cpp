#include "ColliderVisualiser.h"

#include "engine/core/scene/Scene.h"
#include "engine/environment/environment/Environment.h"
#include "engine/tools/debug/Debug.h"
#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/rendering/tools/layer/Layer.h"
#include "engine/modules/rendering/components/model/Model.h"
#include "engine/modules/rendering/components/model/mesh/Mesh.h"
#include "engine/modules/rendering/tools/shaders/unlitShader/UnlitShader.h"
#include "engine/modules/physics/components/collider/Collider.h"
#include "engine/modules/physics/components/collider/sphereCollider/SphereCollider.h"
#include "engine/modules/physics/components/collider/planeCollider/PlaneCollider.h"
#include "engine/modules/physics/components/collider/boxCollider/BoxCollider.h"

using namespace test;

ColliderVisualiser::ColliderVisualiser(Object &object, Collider &collider) :
	Renderer(object, RenderingLayer::Debug),
	_cameraFinder(object.getScene()),
	_collider(&collider),
	_model(nullptr),
	_modelTransformation(1.f)
{
	_desiredRenderingOptions = RenderingOptions::WireframeMode;
}

void ColliderVisualiser::initializeInternally()
{
	_shader = std::make_unique<UnlitShader>();
	if (not _shader->isValid())
	{
		Debug::logError("ColliderRenderer", "Shader is not valid.");
		markBad();
		return;
	}
}

void ColliderVisualiser::prepareInternally()
{
	computeTransformation();
	subscribe(_collider->primitiveChanged, [this](){ computeTransformation(); });

	loadModel();
}

void ColliderVisualiser::render()
{
	auto meshes = _model->getMeshes();
	if (meshes == nullptr)
	{
		Debug::logWarning("ColliderRenderer", "Meshes are invalid.");
		markBad();
		return;
	}

	_shader->use(true);

	_shader->setProjection(_cameraFinder().getProjectionMatrix());
	_shader->setView(_cameraFinder().getViewMatrix());

	for (const auto &mesh : *meshes)
	{
		_shader->setColor(_collider->getCollision() != nullptr ? ActiveColor : NormalColor);

		mesh.bind(true);
		mesh.updateTransformations({ _modelTransformation });
		Environment::renderIndexedBuffer(mesh.getIndices().size());
		mesh.bind(false);
	}

	_shader->use(false);
}

void ColliderVisualiser::loadModel()
{
	switch (_collider->getType())
	{
		case Collider::Type::Plane:
			_model = &getObject().addComponent<Model>("quad.fbx");
			break;

		case Collider::Type::Sphere:
			_model = &getObject().addComponent<Model>("sphere.fbx");
			break;

		case Collider::Type::Box:
			_model = &getObject().addComponent<Model>("cube.fbx");
			break;

		default:
			Debug::logError("ColliderRenderer", "Unknown collider type");
			markBad();
			break;
	}
}

void ColliderVisualiser::computeTransformation()
{
	const auto &transformation = _collider->getObject().selectComponent<Transformation>();

	if (_collider->getType() == Collider::Type::Plane)
	{
		const auto &primitive = static_cast<PlaneCollider *>(_collider)->getPrimitive();
		_modelTransformation = transformation.getParentHeritageMatrix() *
							   translate(primitive.getNormal() * primitive.getDistanceFromOrigin()) *
							   engine::deduceRotationMatrixFromZAxis(primitive.getNormal()) *
							   transformation.getScaleMatrix();
	}
	else if (_collider->getType() == Collider::Type::Sphere)
	{
		const auto &primitive = static_cast<SphereCollider *>(_collider)->getPrimitive();
		_modelTransformation = transformation.getParentHeritageMatrix() *
							   transformation.getTranslationMatrix() *
							   transformation.getRotationMatrix() *
							   scale(vec3(primitive.getRadius() * 2.f));
	}
	else if (_collider->getType() == Collider::Type::Box)
	{
		const auto &primitive = static_cast<BoxCollider *>(_collider)->getPrimitive();
		_modelTransformation = transformation.getParentHeritageMatrix() *
							   transformation.getTranslationMatrix() *
							   transformation.getRotationMatrix() *
							   scale(primitive.getSize());
	}
}