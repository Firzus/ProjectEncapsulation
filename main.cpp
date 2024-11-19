#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"

int main()
{
	bool isSetUp = false;
	int choice;

	Window* window = nullptr;

	std::cout << "Project Encapsulation - BOROS Theo / PRIEU Lilian\n\n";

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
	ColorRGBA shapeColor(255, 0, 0, 255);
	ColorRGBA shapeColor2(0, 0, 255, 255);

	window->createCircle("cercle1", 100, 100, shapeColor, 50);
	window->createCircle("cercle2", 300, 300, shapeColor2, 100);

	while (window->isOpen())
	{
		// Draw
		window->clear(bgColor);
		window->beginDrawing();

		window->getCircle("cercle1")->draw();
		window->getCircle("cercle2")->draw();

		window->endDrawing();

		// Update
		window->getCircle("cercle1")->moove(1, 0);
		window->getCircle("cercle2")->moove(1, 1);
	}

	window->close();
	delete window;
	
	return 0;
}