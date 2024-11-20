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
	window->setFrameRate(60);

	// Props
	ColorRGBA bgColor(255, 255, 255, 255);
	ColorRGBA shapeColor1(255, 0, 0, 255);
	ColorRGBA shapeColor2(0, 255, 0, 255);

	window->createCircle("circle1", 100, 100, shapeColor1, 50);
	window->createCircle("circle2", 300, 100, shapeColor2, 50);

	window->getCircle("circle1")->setDirection(8, 2);

	while (window->isOpen())
	{	
		// Physics
		if (window->getCircle("circle1")->isColliding(window->getCircle("circle2")))
		{
			window->getCircle("circle1")->bounceOfEntity(window->getCircle("circle2"));
			//window->removeCircle("circle2");
		}

		// Inputs handling (Raylib)
		if (window->getCircle("circle1") != nullptr)
		{
			window->getCircle("circle1")->move();
		}

		// GameManager Update
		// Left and right screen collisions
		if (window->getCircle("circle1")->getPosX() - window->getCircle("circle1")->getRadius() <= 0 ||
			window->getCircle("circle1")->getPosX() + window->getCircle("circle1")->getRadius() >= window->getWindowWidth())
		{
			window->getCircle("circle1")->setDirection(-window->getCircle("circle1")->getDirX(), window->getCircle("circle1")->getDirY());
		}

		// Up and down screen collisions
		if (window->getCircle("circle1")->getPosY() - window->getCircle("circle1")->getRadius() <= 0 ||
			window->getCircle("circle1")->getPosY() + window->getCircle("circle1")->getRadius() >= window->getWindowHeight())
		{
			window->getCircle("circle1")->setDirection(window->getCircle("circle1")->getDirX(), -window->getCircle("circle1")->getDirY());
		}

		// Draw
		window->clear(bgColor);
		window->beginDrawing();
		window->update();
		window->endDrawing();
	}

	window->close();
	
	return 0;
}