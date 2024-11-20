#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"

#include "FPSCounter.h"

int main()
{
	bool isSetUp = false;
	int choice;

	FPSCounter fpsCounter;
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

	window->createCircle("circle1", 100, 100, shapeColor1, 50);
	window->createCircle("circle2", 300, 100, shapeColor2, 50);

	int fps = 60;
	window->createText("fpsText", 10, 10, fpsColor, std::to_string(fps) + " fps", 16);

	while (window->isOpen())
	{
		// Physics
		if (window->getCircle("circle1")->isColliding(window->getCircle("circle2")))
		{
			window->removeCircle("circle2");
		}

		if (window->getCircle("circle1") != nullptr)
		{
			window->getCircle("circle1")->move(1, 0);
		}

		window->clear(bgColor);
		window->beginDrawing();
		window->draw();
		window->endDrawing();
	}

	window->close();
	
	return 0;
}