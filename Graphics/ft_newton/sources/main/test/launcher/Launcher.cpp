#include "Launcher.h"

#include "engine/core/processor/Processor.h"
#include "engine/core/scene/object/serialization/Serialization.h"
#include "game/scene/menu/Menu.h"
#include "game/scene/menu/page/Page.h"
#include "game/scene/menu/pageWithSelector/PageWithSelector.h"
#include "game/scene/menu/pageSwitcher/PageSwitcher.h"
#include "game/scene/buttons/sceneLauncher/SceneLauncher.h"
#include "game/scene/buttons/sceneResetter/SceneResetter.h"
#include "game/scene/buttons/sceneCloser/SceneCloser.h"
#include "test/scene/components/instruments/manipulator/Manipulator.h"
#include "test/scene/components/instruments/manipulator/manipulatorController/ManipulatorController.h"
#include "test/scene/components/instruments/shooter/Shooter.h"
#include "test/scene/components/instruments/shooter/shooterController/ShooterController.h"
#include "test/scene/components/instruments/colliderVisualiser/colliderVisualiserController/ColliderVisualiserController.h"
#include "test/scene/components/instruments/collisionVisualiser/CollisionVisualiser.h"
#include "test/scene/components/instruments/collisionVisualiser/collisionVisualiserController/CollisionVisualiserController.h"
#include "test/scene/components/statistics/fpsDisplayer/FpsDisplayer.h"
#include "test/scene/components/statistics/drawCallCountDisplayer/DrawCallCountDisplayer.h"
#include "test/scene/components/statistics/colliderCountDisplayer/ColliderCountDisplayer.h"

using namespace test;

void Launcher::setup()
{
	serialization::registerComponent<game::Menu>();
	serialization::registerComponent<game::Page>();
	serialization::registerComponent<game::PageWithSelector>();
	serialization::registerComponent<game::PageSwitcher>();
	serialization::registerComponent<game::SceneLauncher>();
	serialization::registerComponent<game::SceneResetter>();
	serialization::registerComponent<game::SceneCloser>();

	serialization::registerComponent<test::Manipulator>();
	serialization::registerComponent<test::ManipulatorController>();
	serialization::registerComponent<test::Shooter>();
	serialization::registerComponent<test::ShooterController>();
	serialization::registerComponent<test::ColliderVisualiserController>();
	serialization::registerComponent<test::CollisionVisualiser>();
	serialization::registerComponent<test::CollisionVisualiserController>();
	serialization::registerComponent<test::FpsDisplayer>();
	serialization::registerComponent<test::DrawCallCountDisplayer>();
	serialization::registerComponent<test::ColliderCountDisplayer>();
}

void Launcher::launch()
{
	Processor::launchScene("test/box-box");
}