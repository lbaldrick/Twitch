#include <iostream>
#include "Engine\Engine.h"

using namespace std;

int main() {
	cout << "Hello" << endl;
	
	Engine engine;

	engine.initialize("Twitch");

	while (true) {
		engine.update();
		engine.render();
	}

	return 0;
}