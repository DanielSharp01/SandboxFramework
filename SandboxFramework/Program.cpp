#include <iostream>
#include <GL\glew.h>
#include "MyGameWindow.h"
#include "Utils\Logging.h"
#include "Utils\ConsoleControl.h"
#include "Utils\StringFuncs.h"


int main()
{
	using namespace Sandbox;
	

	ansi::EnableVirtualWinTerminal();

	Logging::LogManager::Get().Subscribe("stdout", [](Logging::LogLevel lvl, const std::string& tag, const std::string& msg)
	{
		return (lvl <= Logging::LogLevel::Info);
	}, [](Logging::LogLevel lvl, const std::string& tag, const std::string& msg)
	{
		switch (lvl)
		{
		case Logging::Error:
			std::cout << ansi::red << "[" << lvl << "] (" << tag << ") " << msg << ansi::reset << std::endl;
			break;
		case Logging::Warning:
			std::cout << ansi::yellow << "[" << lvl << "] (" << tag << ") " << msg << ansi::reset << std::endl;
			break;
		case Logging::Info:
			std::cout << ansi::white << "[" << lvl << "] (" << tag << ") " << msg << ansi::reset << std::endl;
			break;
		}
	});

	MyGameWindow window;
	window.Run();
	

	std::cin.get();

	return 0;
}