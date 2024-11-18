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

	// Initialisation et utilisation de l'encapsulation choisie
	if (window)
	{
		window->init();
		window->createWindow(800, 600, "Nice Ass");

		while (window->isOpen())
		{
			window->clear();
			window->beginDrawing();

			DrawCircle(200, 200, 50, BLUE); // Dessiner un cercle
			DrawCircle(400, 300, 50, BLUE); // Dessiner un cercle

			window->endDrawing();
		}

		window->close();

		delete window;
	}

	return 0;
}