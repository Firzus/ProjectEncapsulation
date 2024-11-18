#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"

int main()
{
	bool isSetUp = false;
	int choice;

	Window* window = nullptr;

	while (!isSetUp)
	{
		std::cout << "RayLib (1) ou SDL (2) ?\n";
		std::cin >> choice;

		system("cls");

		if (choice == 1)
		{
			isSetUp = true;

			std::cout << "RayLib Selected\n";

			window = new WindowRaylib();
		}
		else if (choice == 2)
		{
			isSetUp = true;

			std::cout << "SDL Selected\n";

			window = new WindowSDL();

			window->init();
		}
		else
		{
			std::cout << "Choix invalide. Réessayez.\n";
		}
	}

	// Initialisation et utilisation de l'encapsulation choisie
	if (window)
	{
		window->init();
		window->createWindow(800, 600, "Bouncing Circles");

		while (window->isOpen())
		{
			window->clear();
			// Ajoutez ici le dessin des cercles ou autres éléments
			window->display();
		}

		delete window; // Nettoyage de la mémoire
	}

	return 0;
}