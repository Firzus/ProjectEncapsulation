#pragma once

#include "Text.h"
#include "raylib.h"

class TextRaylib : public Text
{
public:
	TextRaylib(const std::string& label, int x, int y, const ColorRGBA& color, std::string content, int fontSize) : Text(label, x, y, color, content, fontSize) {}

	void draw() const override;
};