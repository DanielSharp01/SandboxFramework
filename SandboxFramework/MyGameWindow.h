#pragma once

#include "Platform\GameWindow.h"
#include <unordered_map>

typedef int Shader;

class MyGameWindow : public Sandbox::Platform::GameWindow
{
private:
	std::unordered_map<std::string, Shader*> shaders;
	std::unordered_map<std::string, Shader*> textures;
	double timer = 0;
public:
	MyGameWindow();
	virtual ~MyGameWindow();
	
	virtual void Update(double delta) override;
	virtual void Draw(double delta) override;
};

