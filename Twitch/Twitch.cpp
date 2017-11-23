#include <iostream>
#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"
#include "Engine\IO\Mouse.h"

using namespace std;

int main() {
	cout << "Hello" << endl;
	
	Engine engine;

	engine.initialize("Twitch");

	Sprite sprite = Sprite("Assets/Art/Biplane.png", -100, -100);

	while (true) {
		engine.update();
		sprite.update();

		sprite.setPos((float)Mouse::getMouseXpos(), (float)Mouse::getMouseYpos());

		engine.beginRender();
		sprite.render();
		engine.endRender();

	}

	return 0;
}