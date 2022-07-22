#include "Game.h"

void Game::initWin()
{

	std::ifstream ifs("config.ini");
	
	std::string title = "clicker2";
	VideoMode windowSize(768, 768);
	unsigned framerateLimit = 120;
	bool vertSinc = false;
	if (ifs.is_open())
	{
		ifs >> windowSize.width >> windowSize.height;
		ifs >> framerateLimit;
		ifs >> vertSinc;
	}
	ifs.close();
	//ContextSettings::
	window = new RenderWindow(windowSize, title);
	window->setFramerateLimit(framerateLimit);
	window->setVerticalSyncEnabled(vertSinc);
}

void Game::initScenes()
{
	scenes.push(new lvl1(window));
}

Game::Game()
{

	initWin();
	initScenes();

}

Game::~Game()
{
	delete window;

	while (scenes.empty())
	{
		delete scenes.top();
		scenes.pop();
	}
}

void Game::endApp()
{
	//saving... i guess?
}

Game& Game::getInstance()
{
	static Game instance;
	return instance;
}

void Game::uptadeDeltaTime()
{
	deltaTime = deltaTimeClock.restart().asSeconds();
}

void Game::updateSfmlEvents()
{
	while (window->pollEvent(sfEvent))
	{
		if (sfEvent.type == Event::Closed)
			window->close();
		if (!scenes.empty())
			scenes.top()->updateSfmlEvents(sfEvent);
	}
}

void Game::update()
{
	updateSfmlEvents();

	if (!scenes.empty())
	{
		scenes.top()->update(deltaTime);
		if (scenes.top()->getQuit())
		{
			scenes.top()->endScene();
			delete scenes.top();
			scenes.pop();
		}
	}
	else
	{
		endApp();
		window->close();
	}
}

void Game::render()
{

	window->clear();

	//
	if (!scenes.empty())
		scenes.top()->render();
	
	window->display();

}

void Game::run()
{
	while (window->isOpen())
	{
		uptadeDeltaTime();
		update();
		render();
	}
}
