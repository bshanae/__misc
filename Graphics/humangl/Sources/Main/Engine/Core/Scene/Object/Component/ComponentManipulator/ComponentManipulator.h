#include <memory>

namespace Engine
{
	class Component;
	class ComponentManipulator;
}

class Engine::ComponentManipulator
{
public :

	/// Mature component is a component, that was prepared and lived more than one frame.
	/// Mature component can be updated and rendered.
	static bool isMature(const std::shared_ptr<Component> &component);

	static void initialize(const std::shared_ptr<Component> &component);
	static void deinitialize(const std::shared_ptr<Component> &component);

	static void prepare(const std::shared_ptr<Component> &component);
	static void update(const std::shared_ptr<Component> &component);
	static void render(const std::shared_ptr<Component> &component);

	static void notifyAboutEndOfFrame(const std::shared_ptr<Component> &component);

private :

	static void assertImmature(const std::shared_ptr<Component> &component);
	static void assertMature(const std::shared_ptr<Component> &component);
};