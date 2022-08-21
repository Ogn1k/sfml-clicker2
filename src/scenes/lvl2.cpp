#include "lvl2.h"

lvl2::lvl2(ScenePublicData* sceneData)
	: Scene(sceneData)
{
	std::ifstream ifs("config.ini");

	if (ifs.is_open())
	{
		ifs >> windowSize.width >> windowSize.height;
	}
	ifs.close();

	menuRect.setPosition(0, 0);
	menuRect.setFillColor(Color(37, 197, 230));

	cirniS.sprite.setOrigin(Vector2f(cirniS.getTexture().getSize().x * 0.5, cirniS.getTexture().getSize().y * 0.5));
	

	dumbbell.setScale(0.5, 0.5);
}

lvl2::~lvl2()
{
	//delete scenes->top();
}

void lvl2::endScene()
{
	sceneData->cirniScale = cirniS.sprite.getScale();
}

void lvl2::updateSfmlEvents(Event event)
{
	houseIconButton.updateEvented(mousePosView, event, true);
	
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (houseIconButton.isPressed())
		{
			endScene();
			Game::getInstance().changeScene(1, sceneData);
		}

	}
}

void lvl2::updateInput(const float& deltatime)
{

	if (Mouse::isButtonPressed(sf::Mouse::Left) && cirniS.sprite.getGlobalBounds().contains(mousePosView) && dumbDone)
	{
		timer = 1.25;
		dumbDone = false;
	}
	if (timer > 0)
	{
		//std::cout << timer << std::endl;
		timer = timer - deltatime;
		if (!(cirniS.sprite.getScale().x <= 0))
		{
			if (timer <= 0.625)
				dumbbell.sprite.move(Vector2f(0, 5 * deltatime * 12));
			else
				dumbbell.sprite.move(Vector2f(0, -5 * deltatime * 12));
		}
		else
		{
			if (timer <= 0.625)
				dumbbell.sprite.move(Vector2f(0, -5 * deltatime * 12));
			else
				dumbbell.sprite.move(Vector2f(0, 5 * deltatime * 12));
		}
		if (timer <= 0)
		{
			sceneData->cirniScale.x -= 0.125;
			sceneData->cirniScale.y -= 0.125;
			sceneData->count--;

			if (cirniS.sprite.getScale().x >= 1)
			{
				dumbbell.sprite.setPosition(cirniS.getPosition().x - 60 * cirniS.sprite.getScale().x, cirniS.getPosition().y + 10 * cirniS.sprite.getScale().y);
			}
			else if (cirniS.sprite.getScale().x <= 0.6 && cirniS.sprite.getScale().x >= 0)
			{
				dumbbell.sprite.setScale(0.5, 0.5);
				dumbbell.sprite.setPosition(cirniS.getPosition().x +10 * cirniS.sprite.getScale().x, cirniS.getPosition().y -60 * cirniS.sprite.getScale().y);
			}
			else if (cirniS.sprite.getScale().x <= -0.5)
			{
				dumbbell.sprite.setScale(-0.5, -0.5);
				dumbbell.sprite.setPosition(cirniS.getPosition().x - 60 * cirniS.sprite.getScale().x, cirniS.getPosition().y + 10 * cirniS.sprite.getScale().y);
			}
		}
	}
	else
	{
		std::cout << cirniS.sprite.getScale().x << std::endl;
		

		
		dumbDone = true;
	}
	
}

void lvl2::update(const float& deltaTime)
{
	cirniS.setScale(sceneData->cirniScale.x, sceneData->cirniScale.y);

	updateInput(deltaTime);
	updateMousePosition();
}

void lvl2::render(RenderTarget* target, RenderStates* states)
{
	if (!target)
		target = window;

	target->draw(menuRect);
	houseIconButton.render(target);

	cirniS.render(target);
	dumbbell.render(target);
}
