#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include "ColorRGBA.h"
#include "Entity.h"

class Component
{
protected:
	std::unordered_map<std::string, Entity*> entities;

public:
	virtual ~Component() = default;

	virtual void createEntity(std::string label, Entity* entity);
	virtual void deleteEntity(const std::string& label);

	virtual void createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize) = 0;
	virtual void createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius) = 0;
	virtual void createSprite(std::string label, int x, int y, std::string texturePath, float rotation, float scale) = 0;

	// Utils
	virtual void loadFont(const std::string& fontPath) = 0;

	//  Getter
	template <typename T>
	T* getEntity(const std::string& label) {
		auto it = entities.find(label);
		if (it != entities.end()) {
			return dynamic_cast<T*>(it->second);
		}
		return nullptr;
	}

	std::unordered_map<std::string, Entity*>& getEntities() { return entities; }
};