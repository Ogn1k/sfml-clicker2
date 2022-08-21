#include "button.h"


button::button(float x, float y, float width, float height, 
	String text, Texture* image, 
	Color idleColor, Color hoverColor, Color activeColor)
{
	buttonS.setTexture(*image);
	buttonS.setPosition(x, y);
	
	texture = *image;

	//buttonT.setString(text);

	buttonSetup(x, y, width, height, text, idleColor, hoverColor, activeColor);
}

button::button(float x, float y, float width, float height,
	String text, std::string image,
	Color idleColor, Color hoverColor, Color activeColor)
{
	if (image == "")
	{

	}
	else if (!texture.loadFromFile(image))
		texture.loadFromFile("textures/missing.png");
	buttonS.setTexture(texture);

	buttonSetup(x, y, width, height, text, idleColor, hoverColor, activeColor);
}



button::~button()
{
	
}

void button::setFont(Font* b_font)
{
	buttonT.setFont(*b_font);
}

void button::buttonSetup(float x, float y, float width, float height, String text, Color idleColor, Color hoverColor, Color activeColor)
{
	buttonState = BTN_IDLE;

	buttonS.setPosition(x, y);
	buttonS.setScale(width / buttonS.getGlobalBounds().width, height / buttonS.getGlobalBounds().height);

	font.loadFromFile("textures/helvetica_regular.otf");
	buttonT.setFont(font);
	buttonT.setString(text);
	buttonT.setFillColor(Color::Black);
	buttonT.setPosition(x, y -8);
	buttonT.setCharacterSize(28);

	buttonBox = RectangleShape(Vector2f(width, height));
	buttonBox.setPosition(x, y);

	this->activeColor = activeColor;
	this->hoverColor = hoverColor;
	this->idleColor = idleColor;
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

void button::buttonBoxfunc(bool act, Vector2f mousePos, int thick, Color color)
{
	buttonBoxAct = act;
	if (buttonBoxAct)
	{
		//std::cout << "asd" << std::endl;
		buttonBox.setOutlineColor(color);
		buttonBox.setOutlineThickness(thick);
		buttonState = BTN_IDLE;
		if (buttonBox.getGlobalBounds().contains(mousePos))
		{
			buttonState = BTN_HOVER;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				buttonState = BTN_ACTIVE;
			}
		}
		if (buttonState == BTN_IDLE)
			buttonBox.setFillColor(idleColor);
		else if (buttonState == BTN_HOVER)
			buttonBox.setFillColor(hoverColor);
		else if (buttonState == BTN_ACTIVE)
			buttonBox.setFillColor(activeColor);
			
	}
}

void button::setOriginCenter()
{
	buttonT.setOrigin(Vector2f(buttonT.getGlobalBounds().width * 0.5, buttonT.getGlobalBounds().height * 0.5));
	buttonBox.setOrigin(Vector2f(buttonBox.getSize().x * 0.5, buttonBox.getSize().y * 0.5));
	
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
		if (buttonState == BTN_IDLE)
			setColorB(idleColor);
		else if (buttonState == BTN_HOVER)
			setColorB(hoverColor);
		else if (buttonState == BTN_ACTIVE)
			setColorB(activeColor);
	}
	else
	{
		if (buttonState == BTN_IDLE)
			buttonS.setColor(idleColor);
		else if (buttonState == BTN_HOVER)
			buttonS.setColor(hoverColor);
		else if (buttonState == BTN_ACTIVE)
			buttonS.setColor(activeColor);
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
		if (buttonState == BTN_IDLE)
			setColorB(idleColor);
		else if (buttonState == BTN_HOVER)
			setColorB(hoverColor);
		else if (buttonState == BTN_ACTIVE)
			setColorB(activeColor);
	}
	else
	{
		if (buttonState == BTN_IDLE)
			buttonS.setColor(idleColor);
		else if (buttonState == BTN_HOVER)
			buttonS.setColor(hoverColor);
		else if (buttonState == BTN_ACTIVE)
			buttonS.setColor(activeColor);
	}
}

void button::render(RenderTarget* target)
{
	
	if (buttonBoxAct)
		target->draw(buttonBox);
	target->draw(buttonS);
	target->draw(buttonT);
}
