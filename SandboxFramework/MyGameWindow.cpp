#include "MyGameWindow.h"
#include <iostream>
#include <fstream>
#include "Utils\Logging.h"

MyGameWindow::MyGameWindow()
	: GameWindow(1600, 900, "Game")
{
	using namespace Sandbox;
	glClearColor(0.392f, 0.584f, 0.929f, 1.0f);
	Logging::LogManager::Get().Log(Logging::Info, "GL version", (const char*)glGetString(GL_VERSION));
}


MyGameWindow::~MyGameWindow()
{
	
}

void MyGameWindow::Update(double delta)
{

}

void MyGameWindow::Draw(double delta)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
