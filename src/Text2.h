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
		font.loadFromFile("textures/sgr-iosevka-term-curly-slab.ttc");
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
	void setString(String StringText)
	{
		text.setString(StringText);
	}
};