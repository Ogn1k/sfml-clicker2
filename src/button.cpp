#include "button.h"


button::button(float x, float y, float width, float height, std::string text, Texture* image, Color idleColor, Color hoverColor, Color activeColor)
{
	buttonState = BTN_IDLE;

	buttonS.setTexture(*image);
	buttonS.setPosition(x, y);
	
	texture = *image;
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

bool button::isHover()
{
	if (buttonState == BTN_HOVER)
		return true;
	return false;
}

const bool button::isPressed() const
{
	if (buttonState == BTN_ACTIVE)
		return true;
	return false;
}

void button::setColorB(Color color)
{
	Image image = texture.copyToImage();
	auto const sz = image.getSize();
	for (std::size_t y = 0; y < sz.y; ++y) {
		for (std::size_t x = 0; x < sz.x; ++x) {
			Color pixel = image.getPixel(x, y);
			pixel.r = 255;
			pixel.g = 255;
			pixel.b = 255;
			image.setPixel(x, y, pixel);
		}
	}
	texture.loadFromImage(image);
	buttonS.setColor(color);
}

void button::updateEvented(Vector2f mousePos, Event event, bool fullColor)
{
	buttonState = BTN_IDLE;
	if (buttonS.getGlobalBounds().contains(mousePos))
	{
		buttonState = BTN_HOVER;
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			buttonState = BTN_ACTIVE;
		}
	}
	if (fullColor)
	{
		switch (buttonState)
		{
		case BTN_IDLE:
			setColorB(idleColor);
			break;
		case BTN_HOVER:
			setColorB(hoverColor);
			break;
		case BTN_ACTIVE:
			setColorB(activeColor);
			break;
		default:
			break;
		}
	}
	else
	{
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
	
}

void button::update(Vector2f mousePos, bool fullColor)
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
	if (fullColor)
	{
		switch (buttonState)
		{
		case BTN_IDLE:
			setColorB(idleColor);
			break;
		case BTN_HOVER:
			setColorB(hoverColor);
			break;
		case BTN_ACTIVE:
			setColorB(activeColor);
			break;
		default:
			break;
		}
	}
	else
	{
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
}

void button::render(RenderTarget* target)
{
	target->draw(buttonS);
}
