#pragma once
#include "lvl1.h"
#include <algorithm>

using namespace sf;

class Game
{
	RenderWindow* window;
	std::vector<Scene*> scenes;
	
	ScenePublicData sceneData;

	Event sfEvent;

	Clock deltaTimeClock;
	float deltaTime;

	Scene* a;
	Scene* b;

	void initWin();
	void initScenes();

public:
	
	Game();
	virtual ~Game();

	void endApp();

	void initSceneData();
	void changeScene(int lvl);

	void uptadeDeltaTime();
	void updateSfmlEvents();
	void update();

	void render();
	void run();
	static Game& getInstance();
};

