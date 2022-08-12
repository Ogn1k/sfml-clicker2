#include "button.h"


button::button(float x, float y, float width, float height, std::string text, Texture* image, Color idleColor, Color hoverColor, Color activeColor)
{
	buttonState = BTN_IDLE;

	buttonS.setTexture(*image);
	buttonS.setPosition(x, y);
	

	//texture.loadFromFile(image);
	//buttonS.setPosition(Vector2f(x, y));
	//buttonS.setTexture(texture);
	buttonS.setScale(width / buttonS.getGlobalBounds().width, height / buttonS.getGlobalBounds().height);

	buttonT.setString(text);
	buttonT.setColor(Color::White);
	buttonT.setPos(buttonS.getPosition().x / 2.f, buttonS.getPosition().y);

	this->activeColor = activeColor;
	this->hoverColor = hoverColor;
	this->idleColor = idleColor;

	this->width = width;
	this->height = height;

}

button::button(float x, float y, float width, float height,
	std::string text, std::string image,
	Color idleColor, Color hoverColor, Color activeColor)
{
	buttonState = BTN_IDLE;
	texture.loadFromFile(image);
	buttonS.setTexture(texture);
	buttonS.setPosition(x, y);

	//texture.loadFromFile(image);
	//buttonS.setPosition(Vector2f(x, y));
	//buttonS.setTexture(texture);
   buttonS.setScale(width / buttonS.getGlobalBounds().width, height / buttonS.getGlobalBounds().height);

	buttonT.setString(text);
	buttonT.setColor(Color::White);
	buttonT.setPos(buttonS.getPosition().x / 2.f, buttonS.getPosition().y );

	this->activeColor = activeColor;
	this->hoverColor = hoverColor;
	this->idleColor = idleColor;

	//buttonS.setColor(Color::Black);
	//buttonS.setColorSimple(this->idleColor);
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
	if (buttonS.getGlobalBounds().contains(mousePos))
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
		buttonS.setColor(idleColor);
		break;
	case BTN_HOVER:
		buttonS.setColor(hoverColor);
		break;
	case BTN_ACTIVE:
		buttonS.setColor(activeColor);
		break;
	default:
		break;
	}
}

void button::render(RenderTarget* target)
{
	target->draw(buttonS);
}
