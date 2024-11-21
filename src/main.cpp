#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"

#include "ComponentRaylib.h"
#include "ComponentSDL.h"

#include "InputManagerRaylib.h"
#include "InputManagerSDL.h"

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
	InputManager* inputManager = nullptr;

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
			inputManager = new InputManagerRaylib();
		}
		else if (libChoice == 2)
		{
			isLibSetUp = true;

			std::cout << "Lib : SDL\n\n";

			window = new WindowSDL();
			component = new ComponentSDL();
			inputManager = new InputManagerSDL();
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

			game = new BrickBreaker(window, component, inputManager);
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
	component->loadFont("resources/fonts/calibri.ttf");

	// FPS
	component->createText("fpsText", 10, 10, ColorRGBA(0, 0, 0, 255), "9999 fps", 16);

	// Game
	game->init();

	// Main loop
	while (window->isOpen())
	{
		inputManager->update();
		game->update();

		component->getEntity<Text>("fpsText")->setContent(std::to_string(window->getFrameRate()) + " fps");

		window->clear(ColorRGBA(255, 255, 255, 255));
		window->beginDrawing();
		window->draw(component->getEntities());
		window->endDrawing();

		if (inputManager->isQuitRequested())
		{
			window->close();
		}
	}

	window->close();

	delete game;
	delete component;
	delete window;
	
	return 0;
}