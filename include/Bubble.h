#pragma once

#include "Game.h"

class Bubble : public Game
{
private:
	ColorRGBA shapeColor1 = { 0, 0, 0, 0 };
	ColorRGBA shapeColor2 = { 0, 0, 0, 0 };
	ColorRGBA shapeColor3 = { 0, 0, 0, 0 };

public:
	Bubble(Window* window, Component* component) : Game(window, component) {}

	void init() override;
	void update() override;
};