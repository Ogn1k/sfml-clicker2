#pragma once
#include "lvl0.h"
#include "lvl2.h"
#include "Game.h"

using namespace sf;

class lvl1 : public Scene
{
protected:
	RectangleShape foodMenuRectIn;
	RectangleShape foodMenuRectOut;
	
	Vector2f fmroSize;
	Vector2f fmriSize;

	VideoMode windowSize = sceneData->windowSize;

	
	bool foodMenu = false;
	float gridSize = 100;

	IntRect offsetX;
	float foodMass;
	float coutSumm;
	Font fontLink;
	
	Texture buttonTexture;

	button foodIconButton = button(windowSize.width / 1.08, -3, 50, 50, "", "textures/food.png", Color::Black, Color::Yellow, Color::Green);
	button workIconButton = button(windowSize.width / 1.18, -3, 50, 50, "", "textures/pack.png", Color::Black, Color::Yellow, Color::Green);

	Sprite2 cirniS = Sprite2("textures/cirni.png", windowSize.width / 2, windowSize.height / 2);
	Sprite2 foodIcon = Sprite2("textures/foodItems.png", 100, 8);

	Text2 countText = Text2(std::to_string(sceneData->count), 30, Color::Green, Color(0, 102, 27));
	RectangleShape background = RectangleShape(Vector2f(windowSize.width, windowSize.height));
	RectangleShape menuRect = RectangleShape(Vector2f(windowSize.width , windowSize.height / 16));
	std::vector < std::vector < button>> buttonsMesh;

	std::list<Entity*> objs;
	EntityPool* pool = EntityPool::getInstance();
public:
	lvl1(ScenePublicData* sceneData);
		
	virtual ~lvl1();
	void menu();
	void endScene();

	void updateSomething(const float& deltatime);

	void updateSfmlEvents(Event event);
	void updateInput(const float& deltatime);
	void updateMenu();
	void update(const float& deltaTime);
	void render(RenderTarget* target = nullptr, RenderStates* states = nullptr);

};

