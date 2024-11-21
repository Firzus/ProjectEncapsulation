#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"

#include "ComponentRaylib.h"
#include "ComponentSDL.h"

int main()
{
	bool isSetUp = false;
	int choice;

	Window* window = nullptr;
	Component* component = nullptr;

	std::cout << "Projet Encapsulation - BOROS Theo / PRIEU Lilian\n\n";

	while (!isSetUp)
	{
		std::cout << "RayLib (1) ou SDL (2) ?\n";
		//std::cin >> choice;

		// For testing purposes
		//choice = 1;
		choice = 2;

		system("cls");

		if (choice == 1)
		{
			isSetUp = true;

			std::cout << "RayLib Selected\n\n";

			window = new WindowRaylib();
			component = new ComponentRaylib();
		}
		else if (choice == 2)
		{
			isSetUp = true;

			std::cout << "SDL Selected\n\n";

			window = new WindowSDL();
			component = new ComponentSDL();
		}
		else
		{
			std::cout << "Choix invalide. Reessayez.\n";
		}
	}

	// Program
	window->init();
	window->createWindow(800, 600, "Window");
	window->setFrameRate(60);

	component->loadFont("resources/fonts/Roboto.ttf");

	// Props
	ColorRGBA bgColor(255, 255, 255, 255);
	ColorRGBA fpsColor(0, 0, 0, 255);
	ColorRGBA shapeColor1(255, 0, 0, 255);
	ColorRGBA shapeColor2(0, 255, 0, 255);
	ColorRGBA shapeColor3(0, 180, 180, 255);


	component->createSprite("spriteTest", 300, 300, "resources/textures/sprite-test.png", 0, 1);

	window->createCircle("circle1", 100, 100, shapeColor1, 25);
	window->createCircle("circle2", 300, 100, shapeColor2, 25);
	window->createCircle("circle3", 500, 500, shapeColor3, 25);

	window->getCircle("circle1")->setDirection(8, 2);
	window->getCircle("circle2")->setDirection(4, -6);
	window->getCircle("circle3")->setDirection(2, 3);

	// Main loop
	while (window->isOpen())
	{
		// Physics
		if (component->getEntity<Circle>("circle1")->isColliding(component->getEntity<Circle>("circle2")))
		{
			component->deleteEntity("circle2");
		}

		for (auto it = window->getCirclesList().begin(); it != window->getCirclesList().end(); ++it)
		{
			// For each circle in the list, check if it collided with another circle of the same list
			for (auto other = window->getCirclesList().begin(); other != window->getCirclesList().end(); ++other)
			{
				if (it->second->isColliding(other->second))
				{
					it->second->bounceOfEntity(other->second);
				}
			}

			// Left and right screen collisions
			if (it->second->getPosX() - it->second->getRadius() <= 0 ||
				it->second->getPosX() + it->second->getRadius() >= window->getWindowWidth())
			{
				it->second->setDirection(-it->second->getDirX(), it->second->getDirY());
			}

			// Up and down screen collisions
			if (it->second->getPosY() - it->second->getRadius() <= 0 ||
				it->second->getPosY() + it->second->getRadius() >= window->getWindowHeight())
			{
				it->second->setDirection(it->second->getDirX(), -it->second->getDirY());
			}
		}
		if (component->getEntity<Circle>("circle1") != nullptr)
		{
			component->getEntity<Circle>("circle1")->move(1, 0);
		}

		// Inputs handling (Raylib)
		for (auto it = window->getCirclesList().begin(); it != window->getCirclesList().end(); ++it)
		{
			if (it->second != nullptr)
			{
				it->second->move();
			}
		}

		component->getEntity<Text>("fpsText")->setContent(std::to_string(window->getFrameRate()) + " fps");

		window->clear(bgColor);
		window->beginDrawing();
		window->draw(component->getEntites());
		window->endDrawing();
	}

	window->close();
	
	return 0;
}