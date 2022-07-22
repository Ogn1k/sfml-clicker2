#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

using namespace sf;

class Scene
{
private:

protected:

	RenderWindow* window;
	std::vector<Texture> textures;
	bool quit;

	Vector2i mousePosScreen;
	Vector2i mousePosWindow;
	Vector2f mousePosView;

public:

	Scene(RenderWindow* window);
	virtual ~Scene();


	const bool& getQuit() const;
	virtual void checkForQuit();
	virtual void endScene() = 0;

	virtual void updateSfmlEvents(Event event) = 0;
	virtual void updateInput(const float& deltatime) = 0;
	virtual void updateMousePosition();
	virtual void update(const float& deltaTime) = 0;
	virtual void render(RenderTarget* target = nullptr) = 0;
};

