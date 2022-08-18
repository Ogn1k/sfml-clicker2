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
	cirniS.setScale(sceneData->cirniScale.x, sceneData->cirniScale.y);
}

lvl2::~lvl2()
{
	//delete scenes->top();
}



void lvl2::updateSfmlEvents(Event event)
{
	houseIconButton.updateEvented(mousePosView, event, true);
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (houseIconButton.isPressed())
		{
			Game::getInstance().changeScene(1);
		}
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			std::cout << cirniS.sprite.getScale().x << cirniS.sprite.getScale().y << std::endl;
		}
	}
}

void lvl2::updateInput(const float& deltatime)
{
}

void lvl2::update(const float& deltaTime)
{
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
}
