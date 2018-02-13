#pragma once

#include "Windowing\GameWindow.h"
#include <unordered_map>

typedef int Shader;

class MyGameWindow : public Sharp::Windowing::GameWindow
{
private:
	std::unordered_map<std::string, Shader*> shaders;
	std::unordered_map<std::string, Shader*> textures;
	double timer = 0;
public:
	MyGameWindow();
	virtual ~MyGameWindow();
	
	virtual void update(double delta) override;
	virtual void draw(double delta) override;
};

