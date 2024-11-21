#pragma once

#include "Game.h"
#include "InputManager.h"

class BrickBreaker : public Game
{
private:
	Circle* ball = nullptr;
	Quadrilateral* player = nullptr;
	int numBricks = 40;
	std::vector<std::string> bricks;
	InputManager* inputManager;

public:
	BrickBreaker(Window* window, Component* component, InputManager* inputManager) : Game(window, component) {
		this->inputManager = inputManager;
	}

	void init() override;
	void update() override;
};

