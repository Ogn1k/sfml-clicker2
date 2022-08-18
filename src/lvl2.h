#pragma once
#include "Scene.h"
#include "lvl1.h"

class lvl2 : public Scene
{
	VideoMode windowSize = VideoMode(768, 768);

	button houseIconButton = button(windowSize.width / 1.08, -3, 50, 50, "", "textures/house.png", Color::Black, Color::Yellow, Color::Green);

	RectangleShape menuRect = RectangleShape(Vector2f(windowSize.width, windowSize.height / 16));

	Sprite2 cirniS = Sprite2("textures/cirni.png", windowSize.width / 2, windowSize.height / 2);

public:
	lvl2(ScenePublicData* sceneData);

	virtual ~lvl2();


	void updateSfmlEvents(Event event);
	void updateInput(const float& deltatime);
	void update(const float& deltaTime);
	void render(RenderTarget* target = nullptr, RenderStates* states = nullptr);
};

