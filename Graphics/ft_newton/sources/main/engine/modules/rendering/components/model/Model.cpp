#include "Model.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "engine/modules/rendering/components/model/modelStorage/ModelStorage.h"

using namespace engine::rendering;

void Model::deserialize(Model &instance, const YAML::Node &node)
{
	instance._fileName = node["file"].as<string>();
}

Model::Model(Object &object) : Component(object)
{}

Model::Model(Object &object, const string &modelName) : Component(object), _fileName(modelName)
{}

engine::shared_ptr<engine::vector<Mesh>> Model::getMeshes() const
{
	return ModelStorage::requestModel(_fileName).lock();
}

void Model::prepareInternally()
{
	ModelStorage::requestModel(_fileName);
}