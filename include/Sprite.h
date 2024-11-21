#pragma once

#include <string>
#include "Entity.h"

class Sprite : public Entity {
protected:
	std::string texturePath;
	float rotation = 0;
	float scale = 1;

public:
	Sprite(const std::string& label, int x, int y, std::string texturePath, float rotation, float scale) : Entity(), texturePath(texturePath), rotation(rotation), scale(scale)
	{
		this->label = label;
		this->posX = x;
		this->posY = y;
	}

    virtual ~Sprite() = default;

	// Physics
	virtual void bounceOfEntity(Entity* other) override;
	virtual bool isColliding(Entity* other) override;


	// Getters - Setters
	float getRotation() const { return rotation; }
	float getScale() const { return scale; }

	void setRotation(float newRotation) { rotation = newRotation; }
	void setScale(float newScale) { scale = newScale; }
	void setTexture(std::string newTexturePath) { texturePath = newTexturePath; }
};
