#pragma once

#include <SFML/Graphics.hpp>
#include "Sprite2.h"
#include "Text2.h"
#include <iostream>

using namespace sf;

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class button 
{
private:
	short unsigned buttonState;
	float width, height;
	//
	Text2 buttonT;

	Color idleColor;
	Color hoverColor;
	Color activeColor;
public:
	button() = default;
	button(float x, float y, float width, float height,
		std::string text, Texture* image,
		Color idleColor, Color hoverColor, Color activeColor);

	button(float x, float y, float width, float height,
		std::string text, std::string image,
		Color idleColor, Color hoverColor, Color activeColor);
	
	~button();

	Texture texture;
	Sprite buttonS;
	//Sprite buttonS;
	//Texture texture;
	const bool isPressed()const;
	void unPress();
	bool isHover();
	void setColorB(Color color);

	void updateEvented(Vector2f mousePos, Event event, bool fullColor = false);
	void update(Vector2f mousePos, bool fullColor = false);
	void render(RenderTarget* target);
};

