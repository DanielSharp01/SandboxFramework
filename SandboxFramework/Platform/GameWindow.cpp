#include "GameWindow.h"
#include <iostream>
#include "..\Utils\Logging.h"

namespace Sandbox::Platform
{
	GameWindow::GameWindow(int width, int height, const char* title)
	{
		windowWidth = width;
		windowHeight = height;

		window = nullptr;
		if (!glfwInit())
		{
			Logging::LogManager::Get().Log(Logging::Error, "INIT", "GLFW failed to initialize!");
			return;
		}
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!window)
		{
			Logging::LogManager::Get().Log(Logging::Error, "INIT", "GLFW failed to create window!");
			return;
		}

		glfwMakeContextCurrent(window);
		if (glewInit() != GLEW_OK)
		{
			Logging::LogManager::Get().Log(Logging::Error, "INIT", "GLEW failed to initialize!");
			return;
		}
	}

	GameWindow::~GameWindow()
	{
		if (window != nullptr) glfwDestroyWindow(window);
		glfwTerminate();
	}

	void GameWindow::Close()
	{
		glfwSetWindowShouldClose(window, true);
	}

	void GameWindow::Run()
	{
		if (window == nullptr) return;

		while (!glfwWindowShouldClose(window))
		{
			double delta = glfwGetTime() - lastTime;
			Update(delta);
			Draw(delta);
			lastTime = glfwGetTime();
			glfwPollEvents();
			glfwSwapBuffers(window);
		}
	}
}