#include <iostream>

#include "Launcher.h"
#include "Exception.h"

int main()
{
	try
	{
		Game::Launcher::setupEngine();
		Game::Launcher::setupGame();
		Game::Launcher::launch();
	}
	catch (const Engine::Exception &exception)
	{
		std::cerr << "Exiting with exception : " << exception.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Exiting with unknown exception." << std::endl;
	}
}