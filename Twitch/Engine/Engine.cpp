#include "Engine.h"
#include "IO/Mouse.h"

int Engine::SCREEN_HEIGHT = 768;
int Engine::SCREEN_WIDTH = 1024;
GLFWwindow* Engine::window = NULL;

Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::initialize(char* windowTitle) {
	if (!glfwInit()) {
		cout << "Error initialising glfw" << endl;
		return false;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);

	if (window == NULL) {
		cout << "Error creating window" << endl;
		return false;
	}

	//glfw Setup
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	glfwSetCursorPosCallback(window, Mouse::posCallback);
	glfwSetMouseButtonCallback(window, Mouse::buttonCallback);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH)/ 2; // get x centre of screen
	int yPos = (mode->height - SCREEN_HEIGHT) / 2; // get y centre of screen

	glfwSetWindowPos(window, xPos, yPos);

	//GL Setup
	//Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	//loads empty identity matrix
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	//Alpha blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void Engine::update() {
	//tells glfw to process events such as mouse move or click
	glfwPollEvents();
}

void Engine::beginRender() {

	glClearColor(0, 1, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::endRender() {
	// swap buffer because glfw uses double buffering on at fore front other in background
	glfwSwapBuffers(window);
}

