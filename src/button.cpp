#include "button.h"

button::button(float x, float y, float width, float height,
	std::string text, std::string image,
	Color idleColor, Color hoverColor, Color activeColor)
{
	buttonState = BTN_IDLE;

	buttonS = Sprite2(image, x, y);
	buttonS.setScale(width / buttonS.getRect().width, height / buttonS.getRect().height);

	buttonT.setString(text);
	buttonT.setColor(Color::White);
	buttonT.setPos(buttonS.getPosition().x / 2.f, buttonS.getPosition().y );

	this->activeColor = activeColor;
	this->hoverColor = hoverColor;
	this->idleColor = idleColor;

	buttonS.setColor(Color::Black);
	buttonS.setColorSimple(this->idleColor);
}

button::~button()
{
}

void button::unPress()
{
	buttonState = BTN_IDLE;
}

const bool button::isPressed() const
{
	if (buttonState == BTN_ACTIVE)
		return true;
	return false;
}



void button::update(Vector2f mousePos)
{
	buttonState = BTN_IDLE;
	if (buttonS.getSprite().getGlobalBounds().contains(mousePos))
	{
		buttonState = BTN_HOVER;
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			buttonState = BTN_ACTIVE;
		}
	}
	switch (buttonState)
	{
	case BTN_IDLE:
		buttonS.setColorSimple(idleColor);
		break;
	case BTN_HOVER:
		buttonS.setColorSimple(hoverColor);
		break;
	case BTN_ACTIVE:
		buttonS.setColorSimple(activeColor);
		break;
	default:
		break;
	}
}

void button::render(RenderTarget* target)
{
	buttonS.render(target);
}
