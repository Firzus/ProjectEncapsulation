#pragma once

#include "Game.h"

class Bubble : public Game
{
private:
	std::vector<Circle*> circles;
	ColorRGBA shapeColor1 = { 0, 0, 0, 0 };
	ColorRGBA shapeColor2 = { 0, 0, 0, 0 };
	ColorRGBA shapeColor3 = { 0, 0, 0, 0 };

public:
	Bubble(Window* window, Component* component) : Game(window, component) {}

	void init() override;
	void update() override;
	void createBubble(std::string label, int x, int y, const ColorRGBA& color, float radius, int speedX, int speedY);
};