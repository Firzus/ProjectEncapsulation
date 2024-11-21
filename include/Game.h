#pragma once

#include "ColorRGBA.h"
#include <Window.h>
#include <Component.h>
#include "Circle.h"
#include "Sprite.h"
#include "Text.h"

class Game
{
protected:
	Window* window;
	Component* component;

public:
	Game(Window* window, Component* component) : window(window), component(component)
	{
		this->window = window;
		this->component = component;
	}

	virtual ~Game() = default;

	virtual void init() = 0;
	virtual void update() = 0;
};

