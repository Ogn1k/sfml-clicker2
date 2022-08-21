#include "lvl0.h"

lvl0::lvl0(ScenePublicData* sceneData)
	: Scene(sceneData)
{
	
	background.setPosition(0, 0);
	background.setFillColor(Color(255, 255, 255));

	title.text.setOrigin(Vector2f(title.text.getGlobalBounds().width * 0.5, title.text.getGlobalBounds().height * 0.5));
	title.setPos(windowSize.width / 2, windowSize.height / 5);

	
	gameStartb.setOriginCenter();
	settingsb.setOriginCenter();
	aboutb.setOriginCenter();
}

lvl0::~lvl0()
{
}

void lvl0::endScene()
{
}

void lvl0::updateSfmlEvents(Event event)
{
}

void lvl0::updateInput(const float& deltatime)
{
}

void lvl0::update(const float& deltaTime)
{
	updateInput(deltaTime);
	updateMousePosition();
	gameStartb.update(mousePosView);
	gameStartb.buttonBoxfunc(true, mousePosView, 5, Color::Black);
	settingsb.buttonBoxfunc(true, mousePosView, 5, Color::Black);
	aboutb.buttonBoxfunc(true, mousePosView, 5, Color::Black);
	if (gameStartb.isPressed())
	{
		Game::getInstance().changeScene(1, sceneData);
	}
}

void lvl0::render(RenderTarget* target, RenderStates* states)
{
	if (!target)
		target = window;

	target->draw(background);
	title.render(target);
	gameStartb.render(target);
	settingsb.render(target);
	aboutb.render(target);
}
