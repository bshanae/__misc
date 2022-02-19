#include "PrototypeStorage.h"
#include "engine/core/scene/object/prototype/Prototype.h"

using namespace engine;

const Prototype &PrototypeStorage::get(const string &path)
{
	if (const auto &iterator = _prototypes.find(path); iterator != _prototypes.end())
		return iterator->second;

	const auto finalPath = _directory + "/" + path + ".yaml";

	const auto result = _prototypes.emplace(path, YAML::LoadFile(finalPath));
	return result.first->second;
}
