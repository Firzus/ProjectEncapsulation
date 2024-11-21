#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"

#include "ComponentRaylib.h"
#include "ComponentSDL.h"

#include "Bubble.h"
#include "BrickBreaker.h"

int main()
{
	bool isLibSetUp = false;
	bool isGameSetUp = false;
	int libChoice;
	int gameChoice;

	Window* window = nullptr;
	Component* component = nullptr;

	Game* game = nullptr;

	std::cout << "Projet Encapsulation - BOROS Theo / PRIEU Lilian\n\n";

	while (!isLibSetUp)
	{
		std::cout << "Choix de la librairie : RayLib (1) ou SDL (2) ?\n";
		std::cin >> libChoice;

		// For testing purposes
		//libChoice = 1;
		//libChoice = 2;

		system("cls");

		if (libChoice == 1)
		{
			isLibSetUp = true;

			std::cout << "Lib : RayLib\n\n";

			window = new WindowRaylib();
			component = new ComponentRaylib();
		}
		else if (libChoice == 2)
		{
			isLibSetUp = true;

			std::cout << "Lib : SDL\n\n";

			window = new WindowSDL();
			component = new ComponentSDL();
		}
		else
		{
			std::cout << "Choix invalide. Reessayez.\n";
		}
	}

	while (!isGameSetUp)
	{
		std::cout << "Choix du jeu : Bulles (1) ou Casse Brique (2) ?\n";
		std::cin >> gameChoice;

		// For testing purposes
		//gameChoice = 1;
		//gameChoice = 2;

		system("cls");

		if (gameChoice == 1)
		{
			isGameSetUp = true;

			std::cout << "Jeu : Bulles\n\n";

			game = new Bubble(window, component);
		}
		else if (gameChoice == 2)
		{
			isGameSetUp = true;

			std::cout << "Jeu : Casse Brique\n\n";

			game = new BrickBreaker(window, component);
		}
		else
		{
			std::cout << "Choix invalide. Reessayez.\n";
		}
	}

	// Program
	window->init();
	window->createWindow(800, 600, "Window");

	// Exception for SDL
	if (libChoice == 2)
	{
		dynamic_cast<ComponentSDL*>(component)->setRenderer(dynamic_cast<WindowSDL*>(window)->getRenderer());
	}

	// Init
	window->setFrameRate(60);
	component->loadFont("resources/fonts/Roboto.ttf");
	ColorRGBA bgColor(255, 255, 255, 255);

	// FPS
	ColorRGBA fpsColor(0, 0, 0, 255);
	component->createText("fpsText", 10, 10, fpsColor, "9999 fps", 16);

	// Game
	game->init();

	// Exemple
	//component->createSprite("spriteTest", 300, 300, "resources/textures/sprite-test.png", 0, 1);

	// Main loop
	while (window->isOpen())
	{
		game->update();

		component->getEntity<Text>("fpsText")->setContent(std::to_string(window->getFrameRate()) + " fps");

		window->clear(bgColor);
		window->beginDrawing();
		window->draw(component->getEntities());
		window->endDrawing();
	}

	window->close();
	
	return 0;
}