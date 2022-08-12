#pragma once
#include "Scene.h"


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
	Sprite2 cirniS = Sprite2("textures/cirni.png", windowSize.width / 2, windowSize.height / 2);
	Sprite2 foodI = Sprite2("textures/food.png", windowSize.width / 1.08, -3);
	Sprite2 foodIcon = Sprite2("textures/Untitled.png", 45, 8);
	Text2 countText = Text2(std::to_string(int(count)), 30, Color::Green, Color(0, 102, 27));
	RectangleShape background = RectangleShape(Vector2f(windowSize.width, windowSize.height));
	RectangleShape menuRect = RectangleShape(Vector2f(windowSize.width , windowSize.height / 16));
	std::vector < std::vector < button>> buttonsMesh;

	std::list<Entity*> objs;
	EntityPool* pool = EntityPool::getInstance();
	//Player p = Player(&buttonTexture);
public:
	lvl1(RenderWindow* window);
		
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

