#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace Sharp::Windowing
{
	class GameWindow
	{
	public:
		GameWindow();
		virtual ~GameWindow();
		bool run();
		void close();
	private:
		GLFWwindow* window;
		int width, height;
		const char* title;
		double lastTime;
	protected:
		virtual void update(double delta) = 0;
		virtual void draw(double delta) = 0;
	};
}