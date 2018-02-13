#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace Sandbox::Platform
{
	class GameWindow
	{
	public:
		GameWindow(int width, int height, const char* title);
		virtual ~GameWindow();
		void Run();
		void Close();
	private:
		GLFWwindow* window;
		int windowWidth, windowHeight;
		double lastTime;
	protected:
		virtual void Update(double delta) = 0;
		virtual void Draw(double delta) = 0;
	};
}