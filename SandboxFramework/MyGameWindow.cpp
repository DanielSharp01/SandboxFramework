#include "MyGameWindow.h"
#include <iostream>
#include <fstream>

MyGameWindow::MyGameWindow()
{
	glClearColor(0.392f, 0.584f, 0.929f, 1.0f);
}


MyGameWindow::~MyGameWindow()
{
	
}

void MyGameWindow::update(double delta)
{

}

void MyGameWindow::draw(double delta)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
