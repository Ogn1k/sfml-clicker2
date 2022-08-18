#pragma once
#include "Scene.h"
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

	VideoMode windowSize = VideoMode(768, 768);

	float count = 0;
	bool foodMenu = false;
	float gridSize = 100;

	IntRect offsetX;
	
	Texture buttonTexture;

	button foodIconButton = button(windowSize.width / 1.08, -3, 50, 50, "", "textures/food.png", Color::Black, Color::Yellow, Color::Green);
	button workIconButton = button(windowSize.width / 1.18, -3, 50, 50, "", "textures/pack.png", Color::Black, Color::Yellow, Color::Green);

	Sprite2 cirniS = Sprite2("textures/cirni.png", windowSize.width / 2, windowSize.height / 2);
	Sprite2 foodIcon = Sprite2("textures/Untitled.png", 45, 8);

	Text2 countText = Text2(std::to_string(int(count)), 30, Color::Green, Color(0, 102, 27));
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

