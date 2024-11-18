#pragma once
class Shape
{
protected:
    //Vector2 position = { 0.0f, 0.0f }; // Position de la forme
    //Color color = {255};

public:
    virtual ~Shape() = default;

    // Renvoie un pointeur générique vers les données
    virtual void* getData() const = 0;
	virtual void setShape() const = 0;
    virtual void setPosition(float x, float y) = 0;
	virtual void setColor() = 0;
};

