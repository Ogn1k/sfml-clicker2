#include "lvl1.h"

lvl1::lvl1(RenderWindow& window)
{
	Sprite2 cirniS("textures/cirni.png", window.getSize().x / 2.5, window.getSize().y / 2.5);
	Sprite2 foodI("textures/food.png", window.getSize().x / 1.08, -3);
	int count = 0;
	Text2 countText(std::to_string(count), 30, Color::Green, Color(0, 102, 27));
	RectangleShape menuRect(Vector2f(window.getSize().x, window.getSize().y / 16));
	menuRect.setPosition(0, 0);
	menuRect.setFillColor(Color(158, 55, 0));
	
	//cirniS.setColor(Color::Green);
	foodI.setColor(Color::Black);
	foodI.setScale(0.4, 0.4);
	//foodI.setOrigin(foodI.getRect().width / 2, foodI.getRect().height / 2);
	menu(window);

	while (window.isOpen())
	{
		Event event; 
		while (window.pollEvent(event)) 
		{ 
			if (event.type == Event::Closed) window.close(); 
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (cirniS.getRect().contains(Mouse::getPosition(window)) && event.mouseButton.button == sf::Mouse::Left)
					{
						countText.setString(std::to_string(count));
						count++;
					}
				}
		}
		if (foodI.getRect().contains(Mouse::getPosition(window)))
		{
			foodI.setColor(Color::Green);
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//menu
				menu(window);
			}
		}
		else
			foodI.setColor(Color::Black);

		window.clear();
		window.draw(menuRect);

		window.draw(countText.getText());
		window.draw(cirniS.getSprite());
		renderer(window);
		window.draw(foodI.getSprite());
		window.display();
	}

}

void lvl1::menu(RenderWindow& window)
{

	foodMenuRectIn = RectangleShape(Vector2f(window.getSize().x / 1.5, window.getSize().y / 2.5));
	foodMenuRectIn.setPosition(window.getSize().x / 1.5, window.getSize().y / 2.5);
	foodMenuRectIn.setFillColor(Color(158, 55, 0));
	
	foodMenuRectOut = RectangleShape(Vector2f(window.getSize().x / 2, window.getSize().y / 3));
	foodMenuRectOut.setPosition(window.getSize().x / 1.5, window.getSize().y / 2.5);
	foodMenuRectOut.setFillColor(Color(158, 55, 0));
	a[0] = foodMenuRectIn;
	a[1] = foodMenuRectOut;
}

void lvl1::renderer(RenderWindow& window)
{

	for (int i = 0; i < sizeof(a); i++)
		window.draw(a[i]);

}
