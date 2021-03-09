#include "openWindow.h"

mainFuncs::mainFuncs()
{
	texture1.loadFromFile("textures/cirni.png");
}

void mainFuncs::openWidnow()
{
	int winWidth = 400; int winHeight = 400;
	RenderWindow window(VideoMode(winWidth, winHeight), "clicker");
	IntRect a((200, 200), (30, 30, 30, 30));
	Sprite cirnis(texture1);
	cirniS = Sprite2(cirniS, texture1, 200, 200);
	while (window.isOpen())
	{
		Event event; while (window.pollEvent(event)) { if (event.type == Event::Closed) window.close(); }

		window.clear();
		window.draw(cirniS);
		window.display();
	}

}