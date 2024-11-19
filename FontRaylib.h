#pragma once

#include "raylib.h"
#include "FontManager.h"

class FontRaylib : public FontManager
{
public:
	FontRaylib() : FontManager() {}

	void loadFont() override;
};