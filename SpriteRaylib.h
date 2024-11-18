#pragma once

#include "Sprite.h"
#include "raylib.h"

class SpriteRaylib : public Sprite {
Texture2D texture;
float x, y;

public:
    void loadImage(const std::string& filePath) override;
    // Renvoie un pointeur g�n�rique vers les donn�es
    virtual void* getData() const override;
    virtual void setPosition(float x, float y) override;
};

