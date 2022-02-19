#pragma once

#include "engine/modules/base/Base.h"

#include "engine/core/scene/object/Object.h"
#include "engine/core/scene/object/component/Component.h"

template <typename T, engine::base::ComponentImportance importance>
class engine::base::ComponentFinder
{
public :

	ComponentFinder(Component &requester) : _requester(requester)
	{}

	virtual ~ComponentFinder() = default;

	inline auto &&operator () () const
	{
		lookForComponentIfNeeded();

		if constexpr (importance == ComponentImportance::Optional)
		{
			return _target;
		}
		else
		{
			Debug::assume(_target != nullptr, "Mandatory component is not found by time it is requested.");
			return *_target;
		}
	}

	inline bool isFound() const
	{
		lookForComponentIfNeeded();
		return _target != nullptr;
	}

private :

	const Component &_requester;

	mutable bool _firstLookUp = true;
	mutable T *_target = nullptr;

	void lookForComponentIfNeeded() const
	{
		if constexpr (importance == ComponentImportance::Optional)
		{
			if (not _firstLookUp)
				return;
		}
		else
		{
			if (_target != nullptr)
				return;
		}

		_firstLookUp = false;
		_target = _requester.getObject().template trySelectComponent<T>();
	}
};