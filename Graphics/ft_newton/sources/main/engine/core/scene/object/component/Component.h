#pragma once

#include "engine/core/Core.h"

#include "engine/tools/templates/eventSystem/EventSystem.h"

/// Consider marking components that don't have child class final as <i>object.selectComponent\<T\>()</i> will works faster on them.
class engine::Component : public Listener
{
public :

	Event<> preparing;
	Event<> prepared;

	Component(Object &object);
	Component(const Component &) = delete;

	virtual ~Component() = default;

	Component &operator = (const Component &) = delete;

	inline Object &getObject() const
	{
		return _object;
	}

	bool isEnabled() const;

	bool isDisabled() const;

	inline bool isPrepared() const
	{
		return _isPrepared;
	}

	/// Mature component is a component, that was prepareInternally and lived more than one frame. Mature component can be updated.
	bool isMature();

	void enable();
	void disable();
	void setEnabled(bool state);

	void markBad();

	void initialize();
	void deinitialize();

	void prepare();
	void processInput();
	void update(float timeDelta);

	void notifyAboutEndOfFrame();

protected :

	/// This event should be used to initialize data of component, that doesn't interact with scene or other components.
	/// At moment of initialization object hierarchy may not built and some components may not be present in the object.
	virtual void initializeInternally() {}

	virtual void deinitializeInternally() {}

	/// This event should be used initialize relations of component with scene and other components.
	virtual void prepareInternally() {}

	/// Input should be read within this events. Component received input even if it disabled.
	virtual void processInputInternally() {}

	virtual void updateInternally(float timeDelta) {}

	virtual void onEnabled() {}
	virtual void onDisabled() {}

private :

	Object &_object;

	bool _isPrepared;
	int _numberOfLivedFrames;
	bool _isEnabled;
	bool _isBad;

	void assertImmature();
	void assertMature();

	void onObjectEnabled();
	void onObjectDisabled();
};