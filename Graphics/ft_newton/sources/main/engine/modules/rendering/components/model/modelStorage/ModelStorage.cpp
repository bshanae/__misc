#include "ModelStorage.h"

#include "engine/modules/rendering/settings/Settings.h"
#include "engine/modules/rendering/components/model/modelParser/ModelParser.h"

using namespace engine::rendering;

engine::weak_ptr<engine::vector<Mesh>> ModelStorage::requestModel(const string &fileName)
{
	if (_modelsByFile.find(fileName) == _modelsByFile.end())
		_modelsByFile[fileName] = ModelParser(fileName, Settings::getNumberOfInstancesOfModel(fileName)).parse();

	return _modelsByFile[fileName];
}

void ModelStorage::clear()
{
	_modelsByFile.clear();
}