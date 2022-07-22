#pragma once

#include <SFML/Graphics.hpp>
#include "Sprite2.h"
#include "Text2.h"

using namespace sf;

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class button
{
private:
	short unsigned buttonState;
	//
	
	Text2 buttonT;

	Color idleColor;
	Color hoverColor;
	Color activeColor;
public:
	Sprite2 buttonS;
	button(float x, float y, float width, float height,
		std::string text, std::string image,
		Color idleColor, Color hoverColor, Color activeColor);
	~button();

	const bool isPressed()const;
	void unPress();

	void update(Vector2f mousePos);
	void render(RenderTarget* target);
};

