#pragma once

#include "Game.h"

class BrickBreaker : public Game
{
public:
	BrickBreaker(Window* window, Component* component) : Game(window, component) {}

	void init() override;
	void update() override;
};
