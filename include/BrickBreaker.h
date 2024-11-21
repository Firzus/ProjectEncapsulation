#pragma once

#include "Game.h"

class BrickBreaker : public Game
{
private:
	int numBricks = 40;

public:
	BrickBreaker(Window* window, Component* component) : Game(window, component) {}

	void init() override;
	void update() override;
};

