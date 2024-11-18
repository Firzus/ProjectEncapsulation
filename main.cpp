#include <iostream>

#include "WindowSDL.h"
#include "WindowRaylib.h"

int main()
{
	bool isSetUp = false;
	int choice;

	while (!isSetUp)
	{
		std::cout << "RayLib (1) ou SDL (2) ?\n";
		std::cin >> choice;

		system("cls");

		if (choice == 1)
		{
			isSetUp = true;
			std::cout << "RayLib Selected\n";
			// RayLib;
			
		}
		if (choice == 2)
		{
			isSetUp = true;
			std::cout << "SDL Selected\n";
			// SDL_Window;
		}
	}
}