#pragma once

#include "Entity.h"
#include "ColorRGBA.h"

class Text : public Entity
{
protected:
    std::string content;
    int fontSize;
    ColorRGBA color;

public:
	Text(const std::string& label, int x, int y, const ColorRGBA& color, std::string content, int fontSize) : Entity(), color(color), content(content), fontSize(fontSize)
	{
		this->label = label;
		this->posX = x;	
		this->posY = y;
	}

    virtual ~Text() = default;

	// Physics
	virtual void bounceOfEntity(Entity* other) override;
	virtual bool isColliding(Entity* other) override;

	// Getters - Setters
	std::string getContent() const { return content; }
	int getFontSize() const { return fontSize; }
	ColorRGBA getColor() const { return ColorRGBA(color); }

    void setContent(const std::string& newContent) { content = newContent; }
    void setFontSize(int size) { fontSize = size; }
    void setColor(const ColorRGBA& newColor) { color = newColor; }
};
