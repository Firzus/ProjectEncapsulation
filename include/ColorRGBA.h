#pragma once
class ColorRGBA
{
int r, g, b, a;

public:
    ColorRGBA(int r, int g, int b, int a);

    // Getters
    int R() const { return r; }
    int G() const { return g; }
    int B() const { return b; }
    int A() const { return a; }
};