#include "GameWindow.h"
#include <iostream>

namespace Sharp::Windowing
{
	GameWindow::GameWindow()
	{
		window = nullptr;
		if (!glfwInit())
		{
			//TODO: LOGGING
			std::cout << "GLFW failed to initialize!" << std::endl;
			return;
		}
		width = 1600;
		height = 900;
		title = "Back to C++";
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!window)
		{
			//TODO: LOGGING
			std::cout << "GLFW failed create a window!" << std::endl;
			return;
		}

		glfwMakeContextCurrent(window);
		if (glewInit() != GLEW_OK)
		{
			//TODO: LOGGING
			std::cout << "GLEW failed to initialize!" << std::endl;
			return;
		}
	}

	GameWindow::~GameWindow()
	{
		if (window != nullptr) glfwDestroyWindow(window);
		glfwTerminate();
	}

	void GameWindow::close()
	{
		glfwSetWindowShouldClose(window, true);
	}

	bool GameWindow::run()
	{
		if (window == nullptr) return false;

		while (!glfwWindowShouldClose(window))
		{
			double delta = glfwGetTime() - lastTime;
			update(delta);
			draw(delta);
			lastTime = glfwGetTime();
			glfwPollEvents();
			glfwSwapBuffers(window);
		}

		return true;
	}
}