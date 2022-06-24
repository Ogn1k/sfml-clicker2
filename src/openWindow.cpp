#include "openWindow.h"
mainFuncs::mainFuncs()
{
	int winWidth = 768; int winHeight = 768;
	RenderWindow window(VideoMode(winWidth, winHeight), "clicker2");
	lvl1 Lvl1(window);
}