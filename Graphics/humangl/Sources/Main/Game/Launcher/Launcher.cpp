#include "Launcher.h"

#include "Window.h"
#include "Processor.h"
#include "SceneParser.h"
#include "ObjectParser.h"
#include "ComponentParser+DefaultCamera.h"
#include "ComponentParser+Model.h"
#include "ComponentParser+Animator.h"
#include "ComponentParser+Renderer.h"
#include "ComponentParser+AmbientLight.h"
#include "ComponentParser+PointLight.h"
#include "ComponentParser+SceneCloser.h"
#include "ComponentParser+MeshSelector.h"
#include "ComponentParser+MeshManipulator.h"

using namespace Game;

void Launcher::setupEngine()
{
	Engine::Window::instantiate();
}

void Launcher::setupGame()
{
	registerComponentParsers();
	parseScene();
}

void Launcher::launch()
{
	Engine::Processor::getInstance()->launchScene(_scene);
}

void Launcher::registerComponentParsers()
{
	Engine::ObjectParser::registerComponentParser<Engine::DefaultCamera>();
	Engine::ObjectParser::registerComponentParser<Engine::Model>();
	Engine::ObjectParser::registerComponentParser<Engine::Animator>();
	Engine::ObjectParser::registerComponentParser<Engine::DefaultRenderer>();
	Engine::ObjectParser::registerComponentParser<Engine::AmbientLight>();
	Engine::ObjectParser::registerComponentParser<Engine::PointLight>();

	Engine::ObjectParser::registerComponentParser<Game::SceneCloser>();
	Engine::ObjectParser::registerComponentParser<Game::MeshSelector>();
	Engine::ObjectParser::registerComponentParser<Game::MeshManipulator>();
}

void Launcher::parseScene()
{
	_scene = Engine::SceneParser::parse("Main");
}