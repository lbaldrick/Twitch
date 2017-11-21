#ifndef TWITCH_ENGINE
#define TWITCH_ENGINE

#include "GLFW\glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>

using namespace std;

class Engine
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	Engine();
	~Engine();

	bool initialize(char* windowTitle);

	void update();
	void render();

private:
	static GLFWwindow* window;
};
#endif 
