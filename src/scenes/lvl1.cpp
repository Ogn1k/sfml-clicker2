#include "lvl1.h"
EntityPool* EntityPool::instance = 0;

lvl1::lvl1(ScenePublicData* sceneData)
	: Scene(sceneData)
{
	
	fontLink.loadFromFile("textures/helvetica_regular.otf");
	
	menuRect.setPosition(0, 0);
	menuRect.setFillColor(Color(37, 197, 230));
	background.setPosition(0, menuRect.getSize().y);
	background.setFillColor(Color(255, 255, 255));
	cirniS.sprite.setOrigin(Vector2f(cirniS.getTexture().getSize().x * 0.5, cirniS.getTexture().getSize().y * 0.5));
	//cirniS.setScale(sceneData->cirniScale.x, sceneData->cirniScale.x);
	
	countText.setPos(15, 8);
	foodIcon.setScale(1, 1);
	foodIcon.setColorSimple(Color(255, 255, 255, 0));

	menu();
}

void lvl1::menu()
{
	fmriSize = Vector2f(windowSize.width / 1.23, windowSize.height / 1.23);
	foodMenuRectIn = RectangleShape(fmriSize);
	foodMenuRectIn.setPosition(windowSize.width / 13, windowSize.height / 9);
	foodMenuRectIn.setFillColor(Color(37, 197, 230));

	fmroSize = Vector2f(windowSize.width / 1.2, windowSize.height / 1.2);
	foodMenuRectOut = RectangleShape(fmroSize);
	foodMenuRectOut.setPosition(windowSize.width / 15, windowSize.height / 10);
	foodMenuRectOut.setFillColor(Color(28, 159, 186));

	buttonTexture.loadFromFile("textures/foodItems.png");
}

lvl1::~lvl1()
{
	
}

void lvl1::endScene()
{
	sceneData->cirniScale = cirniS.sprite.getScale();
}

void lvl1::updateSomething(const float& deltatime)
{
	std::cout << sceneData->count << " | " << coutSumm << std::endl;
	for (auto i : objs)
	{
		i->shoot(Vector2f(0, 1));
		i->update(deltatime);
		//
		if (i->getPos().y >= windowSize.height / 2)
		{
			pool->returnObj(i);
			objs.remove(i);
			break;
		}
		if (i->getSprite().getGlobalBounds().intersects(cirniS.sprite.getGlobalBounds()))
		{
			pool->returnObj(i);
			countText.setString(std::to_string(sceneData->count));
			sceneData->count += coutSumm;
			sceneData->cirniScale.x += foodMass; //0.125
			sceneData->cirniScale.y += foodMass;
			objs.remove(i);
			break;
			
		}
		
	}
}

void lvl1::updateSfmlEvents(Event event)
{
	foodIconButton.updateEvented(mousePosView, event, true);
	workIconButton.updateEvented(mousePosView, event, true);
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if(workIconButton.isPressed())
		{
			endScene();
			Game::getInstance().changeScene(2,sceneData);
			
		}
		if(foodIconButton.isPressed())
		{
			foodMenu = !foodMenu;
		}
		if (foodIcon.sprite.getColor() == Color(255, 255, 255, 255) && !foodMenu && !menuRect.getGlobalBounds().contains(mousePosView))
		{
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				Entity* tempEnt = pool->create(mousePosView, &buttonTexture, offsetX);
				std::cout << tempEnt << std::endl;
				objs.push_front(tempEnt);

			}
		}
	}
}
void lvl1::updateInput(const float& deltatime)
{
	checkForQuit();
}

void lvl1::updateMenu()
{
	buttonsMesh.resize(6, std::vector<button>());

	if (foodMenu)
	{
		for (int x = 0; x < 6; x++)
		{
			buttonsMesh[x].resize(6, button());
			for (int y = 0; y < 6; y++)
			{
				buttonsMesh[x][0] = button(windowSize.width / 10 + x * gridSize, windowSize.width / 8 + 0 * gridSize, 440, 100, "", &buttonTexture, Color::White, Color::Yellow, Color::Green);
				buttonsMesh[x][0].buttonS.setTextureRect(IntRect(x * 40, 0, 40, 40));
				buttonsMesh[x][0].update(mousePosView);
				buttonsMesh[x][0].setFont(&fontLink);
				
				if (buttonsMesh[x][0].isPressed())
				{
					offsetX = IntRect(x * 40, 0, 40, 40);
					foodIcon.setColorSimple(Color(255, 255, 255, 255));
					foodIcon.sprite.setTextureRect(offsetX);
					if (buttonsMesh[0][0].isPressed())
					{
						foodMass = 0.125; coutSumm = 1;
					}
					if (buttonsMesh[1][0].isPressed())
					{
						foodMass = 0.125; coutSumm = 1;
					}
					if (buttonsMesh[2][0].isPressed())
					{
						foodMass = 0.025; coutSumm = 0.2;
					}
					if (buttonsMesh[3][0].isPressed())
					{
						foodMass = 0.25; coutSumm = 2;
					}
					if (buttonsMesh[4][0].isPressed())
					{
						foodMass = 0.5; coutSumm = 4;
					}
					if (buttonsMesh[5][0].isPressed())
					{
						foodMass = -0.00025; coutSumm = -0.002;
					}
				}
			}
		}
	}
}

void lvl1::update(const float& deltatime)
{
	cirniS.setScale(sceneData->cirniScale.x, sceneData->cirniScale.y);

	updateSomething(deltatime);

	updateInput(deltatime);
	updateMousePosition();

	updateMenu();
	
}

void lvl1::render(RenderTarget* target, RenderStates* states)
{
	if (!target)
		target = window;

	target->draw(background);
	target->draw(menuRect);
	foodIconButton.render(target);
	workIconButton.render(target);
	cirniS.render(target);
	countText.render(target);
	foodIcon.render(target);
	if (foodMenu)
	{
		target->draw(foodMenuRectOut);
		target->draw(foodMenuRectIn);
	}
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 1; y++)
		{
			for (auto i : objs)
			{
				i->render(target);
			}
			if (foodMenu)
			{
				buttonsMesh[x][0].render(target);
			}
			//target->draw(p);
			
		}
	} 
	
}


