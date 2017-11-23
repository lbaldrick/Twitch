#ifndef TWITCH_MOUSE
#define TWITCH_MOUSE

#include "GLFW\glfw3.h"

class Mouse {
public:
	static void posCallback(GLFWwindow* window, double _xPos, double _yPos);
	static void buttonCallback(GLFWwindow* window, int button, int action, int mods);

	static double getMouseXpos();
	static double getMouseYpos();

	static bool isButtonDown(int button);
	static bool isButtonUp(int button);
	static bool isButtonPressed(int button);

private:
	static double xPos;
	static double yPos;

	static bool buttons[];
	static bool buttonsDown[];
	static bool buttonsUp[];
};
#endif // !TWITCH_MOUSE

