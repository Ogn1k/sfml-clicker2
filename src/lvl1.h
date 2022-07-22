#pragma once
#include "Scene.h"
#include "Sprite2.h"
#include "Text2.h"
#include "button.h"
#include <iostream>

using namespace sf;

class lvl1 : public Scene
{
protected:
	RectangleShape foodMenuRectIn;
	RectangleShape foodMenuRectOut;
	
	Vector2f fmroSize;
	Vector2f fmriSize;

	VideoMode windowSize = VideoMode(768, 768);

	int count = 0;
	bool foodMenu = false;
	
	//button Button = button(windowSize.width / 1.08, -3, 40, 40, "some text", "textures/food.png", Color::Black, Color::Yellow ,Color::Green);
	Sprite2 cirniS = Sprite2("textures/cirni.png", windowSize.width / 2.5, windowSize.height / 2.5);
	Sprite2 foodI = Sprite2("textures/food.png", windowSize.width / 1.08, -3);
	Text2 countText = Text2(std::to_string(count), 30, Color::Green, Color(0, 102, 27));
	RectangleShape menuRect = RectangleShape(Vector2f(windowSize.width , windowSize.height / 16));
public:
	lvl1(RenderWindow* window);
		
	virtual ~lvl1();
	void menu();

	void endScene();

	void updateSfmlEvents(Event event);
	void updateInput(const float& deltatime);
	void update(const float& deltaTime);
	void render(RenderTarget* target = nullptr);
};

