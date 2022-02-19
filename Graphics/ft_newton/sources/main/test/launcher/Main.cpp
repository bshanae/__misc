#include <iostream>

#include "engine/tools/exceptions/Exception.h"
#include "test/launcher/Launcher.h"

int main()
{
	try
	{
		test::Launcher::setup();
		test::Launcher::launch();
	}
	catch (const engine::Exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Exiting with undefined exception." << std::endl;
	}
}