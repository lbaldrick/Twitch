#include "Mouse.h"

double Mouse::xPos = 0; 
double Mouse::yPos = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 }; 
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::posCallback(GLFWwindow* window, double _xPos, double _yPos) {
	int width, height;

	glfwGetFramebufferSize(window, &width, &height);

	xPos = _xPos;
	yPos = height - _yPos;

}

void Mouse::buttonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button < 0)
		return;

	//if we pressed button
	if (action != GLFW_RELEASE && buttons[button] == false) {
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}

	//if we released button
	if (action == GLFW_RELEASE && buttons[button] == true) {
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}

	buttons[button] = action != GLFW_RELEASE;
}

double Mouse::getMouseXpos() {
	return xPos;
}

double Mouse::getMouseYpos() {
	return yPos;
}

bool Mouse::isButtonDown(int button) {
	bool x = buttonsDown[button];

	buttonsDown[button] = false;

	return x;
}

bool Mouse::isButtonUp(int button) {
	bool x = buttonsUp[button];

	buttonsUp[button] = false;

	return x;
}

bool Mouse::isButtonPressed(int button) {
	return buttons[button];
}