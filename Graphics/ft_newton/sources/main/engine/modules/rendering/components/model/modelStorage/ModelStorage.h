#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/map.h"
#include "engine/tools/external/std/vector.h"
#include "engine/tools/external/std/pointers.h"

class engine::rendering::ModelStorage
{
public :

	ModelStorage() = delete;
	~ModelStorage() = delete;

	static weak_ptr<vector<Mesh>> requestModel(const string &fileName);
	static void clear();

private :

	static inline map<string, shared_ptr<vector<Mesh>>> _modelsByFile;
};
