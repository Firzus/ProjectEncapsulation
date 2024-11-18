#include <iostream>
#include "window.h"

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
			// RayLib;
			std::cout << "RayLil Selected\n";
			
		}
		if (choice == 2)
		{
			isSetUp = true;
			// SDL_Window;
			std::cout << "SDL Selected\n";
		}
	}
}