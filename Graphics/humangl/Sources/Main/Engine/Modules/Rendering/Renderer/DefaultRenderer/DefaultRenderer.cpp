#include "DefaultRenderer.h"

#include "Environment.h"
#include "Scene.h"
#include "DefaultCamera.h"
#include "Model.h"
#include "PointLight.h"
#include "Material.h"
#include "DefaultProgram.h"
#include "AmbientLight.h"
#include "Animator.h"
#include "VectorTools.h"

using namespace Engine;

void DefaultRenderer::prepared()
{
	_program = std::make_unique<DefaultProgram>();

	_camera = getObject()->getScene()->findMandatoryObject("camera")->findMandatoryComponent<DefaultCamera>();
	_model = getObject()->findMandatoryComponent<Engine::Model>();
	_animator = getObject()->findComponent<Engine::Animator>();

	for (const auto &otherObject : getObject()->getScene()->getObjects())
	{
		VectorTools::pushBack(_ambientLights, otherObject->findManyComponents<AmbientLight>());
		VectorTools::pushBack(_pointLights, otherObject->findManyComponents<PointLight>());
	}

	_program->use(true);

	_program->setNumberOfAmbientLights(_ambientLights.size());

	for (int i = 0; i < _ambientLights.size(); i++)
		_program->setAmbientLight(i, _ambientLights[i]->getColor(), _ambientLights[i]->getIntensity());

	_program->setNumberOfPointLights(_pointLights.size());

	for (int i = 0; i < _pointLights.size(); i++)
	{
		_program->setPointLight(
			i,
			_pointLights[i]->getPosition(),
			_pointLights[i]->getColor(),
			_pointLights[i]->getIntensity()
		);
	}

	_program->use(false);
}

void DefaultRenderer::rendered()
{
	_program->use(true);

	_program->setProjection(_camera->getProjection());
	_program->setView(_camera->getView());

	if (_animator != nullptr)
	{
		const auto transforms = _animator->getFinalBoneMatrices();
		for (int i = 0; i < Animation::NumberOfBones; ++i)
			_program->setBone(i, transforms[i]);
	}
	else
	{
		for (int i = 0; i < Animation::NumberOfBones; ++i)
			_program->setBone(i, Matrix4x4::makeIdentity());
	}

	for (const auto &mesh : _model->getMeshes())
	{
		mesh->use(true);

		_program->setTransformation(mesh->getTransformation());
		_program->setMaterialColor(mesh->getActualMaterial()->getColor());

		Environment::renderIndexedBuffer(mesh->getIndices().size());

		mesh->use(false);
	}

	_program->use(false);
}