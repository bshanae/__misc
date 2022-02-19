#include <iostream>

#include "game/launcher/Launcher.h"
#include "engine/tools/exceptions/Exception.h"
#include "engine/tools/exceptions/FatalException.h"

int main()
{
	try
	{
		game::Launcher::setupEngine();
		game::Launcher::setupGame();
		game::Launcher::launch();
	}
	catch (const engine::FatalException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (const engine::Exception &exception)
	{
		std::cerr << "Exiting with engine exception: " << exception.what() << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cerr << "Exiting with an exception: " << exception.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Exiting with undefined exception." << std::endl;
	}
}