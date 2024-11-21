#include "QuadrilateralRaylib.h"

void QuadrilateralRaylib::draw() const
{
    Rectangle rect = {
        posX,
        posY,
        width,
        height
    };

    Vector2 origin = {
        width / 2.0f,
        height / 2.0f
    };

    DrawRectanglePro(
        rect,
        origin,
        rotation,
        Color{
            static_cast<unsigned char>(color.R()),
            static_cast<unsigned char>(color.G()),
            static_cast<unsigned char>(color.B()),
            static_cast<unsigned char>(color.A())
        }
    );
}
