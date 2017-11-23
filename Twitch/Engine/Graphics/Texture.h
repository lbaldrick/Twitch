#ifndef TWITCH_TEXTURE
#define TWITCH_TEXTURE

#include "GLFW\glfw3.h"
#include "SOIL\src\SOIL.h"

#pragma comment(lib, "SOIL.lib")

#include <string>
#include <iostream> 

using namespace std;

class Texture {
public:
	Texture();
	Texture(int id);
	Texture(string path);

	int getId();
	int getWidth();
	int getHeight();

private:
	bool getTextureParams();
	int id;
	int width;
	int height;
};
#endif // !TWITCH_TEXTURE

