#pragma once

#include <string>

class Sprite {
public:
    virtual ~Sprite() = default;

    virtual void loadImage(const std::string& filePath) = 0;
    // Renvoie un pointeur générique vers les données
    virtual void* getData() const = 0;
    virtual void setPosition(float x, float y) = 0;
};
