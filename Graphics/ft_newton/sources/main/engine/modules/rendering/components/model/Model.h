#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/external/std/pointers.h"

class engine::rendering::Model final : public Component
{
public :

	inline static const string typeName = "model";
	static void deserialize(Model &instance, const YAML::Node &node);

	Model(Object &object);
	Model(Object &object, const string &modelName);

	~Model() override = default;

	inline const string &getFileName() const
	{
		return _fileName;
	}

	/// Can be null
	shared_ptr<vector<Mesh>> getMeshes() const;

protected :

	void prepareInternally() override;

private :

	string _fileName;
};