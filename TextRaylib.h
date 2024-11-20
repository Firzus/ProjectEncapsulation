#pragma once

#include "Text.h"
#include "raylib.h"

class TextRaylib : public Text
{
private:
	Font customFont;

public:
	TextRaylib(Font customFont, const std::string& label, int x, int y, const ColorRGBA& color, std::string content, int fontSize) : Text(label, x, y, color, content, fontSize)
	{
		this->customFont = customFont;
	}

	void draw() const override;
};