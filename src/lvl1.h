#pragma once
#include <SFML/Graphics.hpp>
#include "Sprite2.h"
#include "Text2.h"
#include <string> 
#include <iostream>

using namespace sf;
class lvl1
{
private:
	RectangleShape a[2];
	RectangleShape foodMenuRectIn;
	RectangleShape foodMenuRectOut;
public:
	lvl1(RenderWindow& window);
	void menu(RenderWindow& window);
	void renderer(RenderWindow& window);
};

