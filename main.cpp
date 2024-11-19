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
		choice = 1;
		//choice = 2;

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
	ColorRGBA shapeColor(255, 0, 0, 255);

	window->createCircle("cercle1", 100, 100, shapeColor, 50);

	while (window->isOpen())
	{
		// Inputs handling (Raylib)
		//if (IsKeyDown(KEY_RIGHT) && window->getCircle("cercle1") != nullptr)
		//{
		//	window->getCircle("cercle1")->move(1, 0);
		//}

		//if (IsKeyDown(KEY_SPACE) && window->getCircle("cercle1") != nullptr)
		//{
		//	window->removeCircle("cercle1");
		//}

		// Draw
		window->clear(bgColor);
		window->beginDrawing();
		window->update();
		window->endDrawing();
	}

	window->close();
	
	return 0;
}