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
		choice = 1;
		//choice = 2;

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

	component->loadFont("assets/font/Roboto.ttf");

	// Props
	ColorRGBA bgColor(255, 255, 255, 255);
	ColorRGBA fpsColor(0, 0, 0, 255);
	ColorRGBA shapeColor1(255, 0, 0, 255);
	ColorRGBA shapeColor2(0, 255, 0, 255);

	component->createCircle("circle1", 100, 100, shapeColor1, 50);
	component->createCircle("circle2", 300, 100, shapeColor2, 50);

	component->createText("fpsText", 10, 10, fpsColor,"9999 fps", 16);

	// Main loop
	while (window->isOpen())
	{
		// Physics
		if (component->getEntity<Circle>("circle1")->isColliding(component->getEntity<Circle>("circle2")))
		{
			component->deleteEntity("circle2");
		}

		if (component->getEntity<Circle>("circle1") != nullptr)
		{
			component->getEntity<Circle>("circle1")->move(1, 0);
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