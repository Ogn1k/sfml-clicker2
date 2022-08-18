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
	a = new lvl1(&sceneData);
	b = new lvl2(&sceneData);
	scenes.push_back(a);
	//scenes.push(new lvl2(window, &scenes));
	
}

void Game::initSceneData()
{
	sceneData.window = window;
	sceneData.scenes = &scenes;
}

Game::Game()
{

	initWin();
	initSceneData();
	initScenes();
	

}

Game::~Game()
{
	delete window;

	while (scenes.empty())
	{
		delete scenes.back();
		scenes.pop_back();
	}
}

void Game::endApp()
{
	//saving... i guess?
}



void Game::changeScene(int lvl)
{
	if (lvl == 1)
	{

		std::cout << "aa" << std::endl;
		scenes.front() = a;

	}
	if(lvl == 2)
	{
		std::cout << "bb" << std::endl;
		scenes.back() = b;
		
	}
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
			scenes.back()->updateSfmlEvents(sfEvent);
	}
}

void Game::update()
{
	updateSfmlEvents();

	if (!scenes.empty())
	{
		scenes.back()->update(deltaTime);
		if (scenes.back()->getQuit())
		{
			scenes.back()->endScene();
			delete scenes.back();
			scenes.back();
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
		scenes.back()->render();
	
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
