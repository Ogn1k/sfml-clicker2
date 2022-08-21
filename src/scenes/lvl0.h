#pragma once
#include "Scene.h"
#include "lvl1.h"

class lvl0 : public Scene
{
	VideoMode windowSize = sceneData->windowSize;
	Text2 title = Text2("game title xd", 48, Color::Black);
	RectangleShape background = RectangleShape(Vector2f(windowSize.width, windowSize.height));
	std::wstring te1 = L"Начать", te2 = L"Настройки", te3 = L"ОБ";
	button gameStartb = button(windowSize.width / 2, windowSize.height / 1.8, 200, 50, te1, "", Color::White, Color::Yellow, Color::Green);
	button settingsb = button(windowSize.width / 2, windowSize.height / 1.5, 200, 50, te2, "asd", Color::White, Color::Yellow, Color::Green);
	button aboutb = button(windowSize.width / 2, windowSize.height / 1.3, 200, 50, te3, "asd", Color::White, Color::Yellow, Color::Green);
public:
	lvl0(ScenePublicData* sceneData);

	virtual ~lvl0();
	void endScene();

	void updateSfmlEvents(Event event);
	void updateInput(const float& deltatime);
	void update(const float& deltaTime);
	void render(RenderTarget* target = nullptr, RenderStates* states = nullptr);
};

		