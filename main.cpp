#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"

int main()
{
	bool isSetUp = false;
	int choice;

	Window* window = nullptr;

	std::cout << "Project Encapsulation - BOROS Théo / PRIEU Lilian\n";

	while (!isSetUp)
	{
		std::cout << "RayLib (1) ou SDL (2) ?\n";
		std::cin >> choice;

		//choice = 1; // For testing purposes

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
			std::cout << "Choix invalide. Réessayez.\n";
		}
	}

	// Position et taille du cercle
	int circleX = 400; // Position X (au centre de l'écran)
	int circleY = 300; // Position Y (au centre de l'écran)
	int circleRadius = 50; // Rayon du cercle

	// Initialisation et utilisation de l'encapsulation choisie
	if (window)
	{
		window->init();
		window->createWindow(800, 600, "Nice Ass");

		while (window->isOpen())
		{
			window->clear();

			//window->draw();
			// Dessiner le cercle (position X, Y et rayon)
			DrawCircle(circleX, circleY, circleRadius, BLUE); // Cercle bleu

			window->display();
		}

		window->close();

		delete window;
	}

	return 0;
}