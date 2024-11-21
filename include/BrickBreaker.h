#pragma once

#include "Game.h"

class BrickBreaker : public Game
{
private:
	Circle* ball;
	Quadrilateral* player;
	int numBricks = 40;
	std::vector<std::string> bricks;

public:
	BrickBreaker(Window* window, Component* component) : Game(window, component) {}

	void init() override;
	void update() override;
};

