#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW\glfw3.h"
#include "Texture.h"

#include <iostream>
#include <string>


using namespace std;

class Sprite {
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float _xPos, float _yPos);

	void update();
	void render();

	void setPos(float _xPos, float _yPos);
	void setRot(float _rot);

private:
	Texture texture;
	float xPos;
	float yPos;
	float rot;
};
#endif // !1
