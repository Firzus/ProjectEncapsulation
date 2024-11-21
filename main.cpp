#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"

int main()
{
	bool isSetUp = false;
	int choice;

	Window* window = nullptr;

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
		}
		else if (choice == 2)
		{
			isSetUp = true;

			std::cout << "SDL Selected\n\n";

			window = new WindowSDL();
		}
		else
		{
			std::cout << "Choix invalide. Reessayez.\n";
		}
	}

	// Program
	window->init();
	window->createWindow(800, 600, "Window");
	window->loadFont("assets/font/Roboto.ttf");
	window->setFrameRate(60);

	// Props
	ColorRGBA bgColor(255, 255, 255, 255);
	ColorRGBA fpsColor(0, 0, 0, 255);
	ColorRGBA shapeColor1(255, 0, 0, 255);
	ColorRGBA shapeColor2(0, 255, 0, 255);
	ColorRGBA shapeColor3(0, 180, 180, 255);


	window->createText("fpsText", 10, 10, fpsColor,"9999 fps", 16);

	window->createCircle("circle1", 100, 100, shapeColor1, 25);
	window->createCircle("circle2", 300, 100, shapeColor2, 25);
	window->createCircle("circle3", 500, 500, shapeColor3, 25);

	window->getCircle("circle1")->setDirection(8, 2);
	window->getCircle("circle2")->setDirection(4, -6);
	window->getCircle("circle3")->setDirection(2, 3);

	while (window->isOpen())
	{
		// Physics
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

		// Inputs handling (Raylib)
		for (auto it = window->getCirclesList().begin(); it != window->getCirclesList().end(); ++it)
		{
			if (it->second != nullptr)
			{
				it->second->move();
			}
		}

		window->clear(bgColor);
		window->beginDrawing();
		window->getText("fpsText")->setContent(std::to_string(window->getFrameRate()) + " fps");
		window->draw();
		window->endDrawing();
	}

	window->close();
	
	return 0;
}