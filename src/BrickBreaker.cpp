#include "BrickBreaker.h"

void BrickBreaker::init()
{
	component->createQuadrilateral("player", 400, 580, ColorRGBA(2, 6, 23, 255), 150, 20, 0);
	component->createCircle("ball", 400, 300, ColorRGBA(203, 213, 225, 255), 15);
	
	// Bricks
    for (int i = 0; i < numBricks; ++i) {
        int x = (i % 8) * 100;
        int y = (i / 8) * 40;

        component->createSprite("brick" + std::to_string(i + 1), x, y, "resources/textures/bricks/brick-" + std::to_string(i + 1) + ".png", 0, 1.0f);
    }
}

void BrickBreaker::update()
{
	//component->getEntity<Quadrilateral>("player")->move();
}
