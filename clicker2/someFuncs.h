#include <SFML/Graphics.hpp>
using namespace sf;

Sprite Sprite2(Sprite sprite, Texture texture, int x, int y)
{
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	return sprite;
}