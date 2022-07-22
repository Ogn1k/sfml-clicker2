#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Text2
{
private:
	Font font;
	Text text;
public:
	Text2(String StringText= "no text", int size = 28, Color color = Color::Red, Color color2=Color::Transparent , int thicknes=1)
	{
		font.loadFromFile("textures/helvetica_regular.otf");
		text.setFont(font);
		text.setString(StringText);
		text.setCharacterSize(size);
		text.setFillColor(color);
		text.setOutlineColor(color2 );
		text.setOutlineThickness(thicknes);
	}
	Text getText()
	{
		return text;
	}
	Font getFont()
	{
		return font;
	}
	void setString(String StringText)
	{
		text.setString(StringText);
	}
	void setColor(Color color)
	{
		text.setFillColor(color);
	}
	void setPos(float x, float y)
	{
		text.setPosition(Vector2f(x, y));
	}
	virtual void update(const float& deltatime)
	{
	}
	virtual void render(RenderTarget* target)
	{
		target->draw(getText());
	}
};