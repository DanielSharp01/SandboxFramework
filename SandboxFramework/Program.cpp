#include <iostream>
#include <GL\glew.h>
#include "MyGameWindow.h"

int main()
{
	using namespace Sharp::Windowing;
	MyGameWindow window;
	if (!window.run()) std::cin.get();

	return 0;
}