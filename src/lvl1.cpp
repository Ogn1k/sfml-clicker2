#include "lvl1.h"
#include <iostream>

lvl1::lvl1(RenderWindow* window)
	: Scene(window)
{

	std::ifstream ifs("config.ini");

	if (ifs.is_open())
	{
		ifs >> windowSize.width >> windowSize.height;
	}
	ifs.close();
	menuRect.setPosition(0, 0);
	menuRect.setFillColor(Color(37, 197, 230));
	foodI.setColor(Color::Black);
	foodI.setScale(0.4, 0.4);
	cirniS.setScale(1.4, 1.4);

	menu();
}

void lvl1::menu()
{

	fmriSize = Vector2f(windowSize.width / 1.23, windowSize.height / 1.23);
	foodMenuRectIn = RectangleShape(fmriSize);
	foodMenuRectIn.setPosition(windowSize.width / 13, windowSize.height / 9);
	foodMenuRectIn.setFillColor(Color(37, 197, 230));

	fmroSize = Vector2f(windowSize.width / 1.2, windowSize.height / 1.2);
	foodMenuRectOut = RectangleShape(fmroSize);
	foodMenuRectOut.setPosition(windowSize.width / 15, windowSize.height / 10);
	foodMenuRectOut.setFillColor(Color(28, 159, 186));

	
	
}


lvl1::~lvl1()
{
}

void lvl1::endScene()
{
	//saving
}

void lvl1::updateSfmlEvents(Event event)
{

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (cirniS.getRect().contains(Mouse::getPosition(*window)) && event.mouseButton.button == sf::Mouse::Left && !foodMenu)
			{
				countText.setString(std::to_string(count));
				count++;
			}
			if (foodI.getRect().contains(Mouse::getPosition(*window)) && event.mouseButton.button == sf::Mouse::Left)
			{
				foodMenu = !foodMenu;
			}
		}

}

void lvl1::updateInput(const float& deltatime)
{
	checkForQuit();
}

void lvl1::update(const float& deltatime)
{
	updateInput(deltatime);
	updateMousePosition();
	if(!foodMenu)
	{
		foodMenuRectIn.setSize(Vector2f(0, 0));
		foodMenuRectOut.setSize(Vector2f(0, 0));
	}
	else
	{
		foodMenuRectIn.setSize(fmriSize);
		foodMenuRectOut.setSize(fmroSize);
	}
}

void lvl1::render(RenderTarget* target)
{
	if (!target)
		target = window;
	
	target->draw(menuRect);
	foodI.render(target);
	cirniS.render(target);
	countText.render(target);
	target->draw(foodMenuRectOut);
	target->draw(foodMenuRectIn);
	
	
}
