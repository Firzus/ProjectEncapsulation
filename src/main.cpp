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

	// Exception for SDL
	if (choice == 2)
	{
		dynamic_cast<ComponentSDL*>(component)->setRenderer(dynamic_cast<WindowSDL*>(window)->getRenderer());
	}

	window->setFrameRate(60);
	component->loadFont("resources/fonts/calibri.ttf");

	// Props
	ColorRGBA bgColor(255, 255, 255, 255);
	ColorRGBA fpsColor(0, 0, 0, 255);
	ColorRGBA shapeColor1(255, 0, 0, 255);
	ColorRGBA shapeColor2(0, 255, 0, 255);
	ColorRGBA shapeColor3(0, 180, 180, 255);

	component->createSprite("spriteTest", 300, 300, "resources/textures/sprite-test.png", 0, 1);

	component->createCircle("circle1", 100, 100, shapeColor1, 25);
	component->createCircle("circle2", 300, 100, shapeColor2, 25);
	component->createCircle("circle3", 500, 500, shapeColor3, 25);

	component->createText("fpsText", 10, 10, fpsColor, "9999 fps", 16);

	component->getEntity<Circle>("circle1")->setDirection(8, 2);
	component->getEntity<Circle>("circle2")->setDirection(4, -6);
	component->getEntity<Circle>("circle3")->setDirection(2, 3);

	// Main loop
	while (window->isOpen())
	{
		// Physics and collisions
		for (auto it = component->getEntities().begin(); it != component->getEntities().end(); ++it)
		{
			// For each component in the list, check if it collided with another component of the same list
			for (auto other = component->getEntities().begin(); other != component->getEntities().end(); ++other)
			{
				if (it->second->isColliding(other->second))
				{
					it->second->bounceOfEntity(other->second);
				}
			}

			// Verify the actual component is a circle
			if (dynamic_cast<Circle*>(it->second))
			{
				Circle* circle = dynamic_cast<Circle*>(it->second);

				// Left and right screen collisions
				if (circle->getPosX() - circle->getRadius() <= 0 ||
					circle->getPosX() + circle->getRadius() >= window->getWindowWidth())
				{
					it->second->setDirection(-it->second->getDirX(), it->second->getDirY());
				}

				// Up and down screen collisions
				if (circle->getPosY() - circle->getRadius() <= 0 ||
					circle->getPosY() + circle->getRadius() >= window->getWindowHeight())
				{
					circle->setDirection(circle->getDirX(), -circle->getDirY());
				}
			}
		}

		// Call the move function for every components in the list
		for (auto it = component->getEntities().begin(); it != component->getEntities().end(); ++it)
		{
			if (it->second != nullptr)
			{
				it->second->move();
			}
		}

		component->getEntity<Text>("fpsText")->setContent(std::to_string(window->getFrameRate()) + " fps");

		window->clear(bgColor);
		window->beginDrawing();
		window->draw(component->getEntities());
		window->endDrawing();
	}

	window->close();
	
	return 0;
}