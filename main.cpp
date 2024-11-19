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
	window->createCircle("cercle2", 300, 300, shapeColor, 100);

	while (window->isOpen())
	{
		// Draw
		window->clear(bgColor);
		window->beginDrawing();

		window->getCircle("cercle1")->draw();
		window->getCircle("cercle2")->draw();

		window->endDrawing();

		// Update
		window->getCircle("cercle1")->move(1, 0);

		// Inputs handling (Raylib)
		if (IsKeyDown(KEY_DOWN)) window->getCircle("cercle2")->move(0, 1);
		if (IsKeyDown(KEY_UP)) window->getCircle("cercle2")->move(0, -1);
		if (IsKeyDown(KEY_LEFT)) window->getCircle("cercle2")->move(-1, 0);
		if (IsKeyDown(KEY_RIGHT)) window->getCircle("cercle2")->move(1, 0);

		if (IsKeyDown(KEY_SPACE)) window->removeCircle("cercle2");
	}

	window->close();
	delete window;
	
	return 0;
}