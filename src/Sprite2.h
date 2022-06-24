#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Sprite2
{
private:
	Sprite sprite;
	Image image;
	Texture texture;
	IntRect box;
	RectangleShape debugBox;
	float originX, originY, scaleX, scaleY;
public:

	Sprite2(String patch= "textures/missing.png", int x = 0, int y = 0)
	{
		image.loadFromFile(patch);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(x, y);

		box = IntRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getTextureRect().width, sprite.getTextureRect().height);

		
		
	}
	Sprite getSprite()
	{
		return sprite;
	}
	Texture getTexture()
	{
		return texture;
	}
	IntRect getRect()
	{
		box = IntRect(sprite.getPosition().x, sprite.getPosition().y , sprite.getTextureRect().width * scaleX, sprite.getTextureRect().height * scaleY);
		return box;
	}
	void setColor(Color color)
	{
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
		sprite.setColor(color);
	}
	void setOrigin(float x, float y)
	{
		originX = x; originY = y;
		sprite.setOrigin(Vector2f(x, y));
	}
	void setScale(float width, float height)
	{
		scaleX = width; scaleY = height;
		sprite.setScale(Vector2f(width, height));
	}
	RectangleShape renderDebug()
	{
		debugBox.setPosition(Vector2f(sprite.getPosition().x , sprite.getPosition().y));
		debugBox.setSize(Vector2f(box.width, box.height));

		return debugBox;
	}
};

