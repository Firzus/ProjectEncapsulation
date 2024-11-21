#include "QuadrilateralRaylib.h"

void QuadrilateralRaylib::draw() const
{
    Rectangle rect = {
        posX,
        posY,
        width,
        height
    };

    DrawRectanglePro(
        rect,
        Vector2{0, 0},
        rotation,
        Color{
            static_cast<unsigned char>(color.R()),
            static_cast<unsigned char>(color.G()),
            static_cast<unsigned char>(color.B()),
            static_cast<unsigned char>(color.A())
        }
    );
}
