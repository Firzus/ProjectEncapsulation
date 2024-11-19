#pragma once

class FontManager
{
public:
	virtual ~FontManager() = default;

	virtual void loadFont() = 0;
};