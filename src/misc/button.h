#pragma once

#include "Sprite2.h"
#include "Text2.h"

using namespace sf;

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class button 
{
	short unsigned buttonState;
	float width, height;
	bool buttonBoxAct = false;
	//
	Font font;
	Text buttonT;
	RectangleShape buttonBox;

	Color idleColor;
	Color hoverColor;
	Color activeColor;

	void buttonSetup(float x, float y, float width, float height, String text, Color idleColor, Color hoverColor, Color activeColor);
	void setColorB(Color color);

public:
	button() = default;
	button(float x, float y, float width, float height,
		String text, Texture* image,
		Color idleColor, Color hoverColor, Color activeColor);

	button(float x, float y, float width, float height,
		String text, std::string image,
		Color idleColor, Color hoverColor, Color activeColor);
	
	~button();

	void setFont(Font* b_font);
	
	Texture texture;
	Sprite buttonS;
	//Sprite buttonS;
	//Texture texture;
	const bool isPressed()const;
	void unPress();
	bool isHover();
	
	void buttonBoxfunc(bool act, Vector2f mousePos, int thick = 0, Color color = Color::Transparent);
	void setOriginCenter();

	void updateEvented(Vector2f mousePos, Event event, bool fullColor = false);
	void update(Vector2f mousePos, bool fullColor = false);
	void render(RenderTarget* target);
};

