#pragma once
#include "lvl1.h"

using namespace sf;

class Game
{
private:

	RenderWindow *window;
	Event sfEvent;

	Clock deltaTimeClock;
	float deltaTime;

	std::stack<Scene*> scenes;

	void initWin();
	void initScenes();

public:
	Game();
	virtual ~Game();

	void endApp();

	void uptadeDeltaTime();
	void updateSfmlEvents();
	void update();

	void render();
	void run();
	static Game& getInstance();
};

