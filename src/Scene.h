#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include "Text2.h"
#include "button.h"
#include "poolManager.h"


using namespace sf;

class Scene;

struct ScenePublicData
{
	ScenePublicData() {}
	RenderWindow* window;
	std::vector<Scene*>* scenes;
	Vector2f cirniScale;
};

class Scene
{
private:

protected:
	ScenePublicData* sceneData;

	std::vector<Scene*>* scenes;

	RenderWindow* window;
	bool quit;

	Vector2i mousePosScreen;
	Vector2i mousePosWindow;
	Vector2f mousePosView;

public:

	Scene(ScenePublicData* sceneData );
	virtual ~Scene();
	

	const bool& getQuit() const;
	virtual void checkForQuit();
	virtual void endScene();

	virtual void updateSfmlEvents(Event event) = 0;
	virtual void updateInput(const float& deltatime) = 0;
	virtual void updateMousePosition();
	virtual void update(const float& deltaTime) = 0;
	virtual void render(RenderTarget* target = nullptr, RenderStates* states = nullptr) = 0;
};

