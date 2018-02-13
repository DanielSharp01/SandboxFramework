#pragma once

#include <string>

namespace Sandbox::ansi
{
	const std::string white("\x1b[0;97m");
	const std::string red("\x1b[0;91m");
	const std::string yellow("\x1b[0;93m");
	const std::string reset("\x1b[0m");

	void EnableVirtualWinTerminal();
}