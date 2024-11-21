#include "BrickBreaker.h"

void BrickBreaker::init()
{
	component->createQuadrilateral("player", 400, 580, ColorRGBA(2, 6, 23, 255), 150, 20, 0);
	component->createCircle("ball", 400, 500, ColorRGBA(203, 213, 225, 255), 15);
	player = component->getEntity<Quadrilateral>("player");
	ball = component->getEntity<Circle>("ball");
	ball->setDirX(3);
	ball->setDirY(-3);

	// Bricks
    for (int i = 0; i < numBricks; ++i) {
        int x = (i % 8) * 100;
        int y = (i / 8) * 40;

        component->createSprite("brick" + std::to_string(i + 1), x, y, "resources/textures/bricks/brick-" + std::to_string(i + 1) + ".png", 0, 1.0f);
		
		// Add the brick to the list
		bricks.push_back("brick" + std::to_string(i + 1));
	}
}

void BrickBreaker::update()
{
    // Vérification des collisions avec les murs
    if (ball->getPosX() - ball->getRadius() <= 0 || ball->getPosX() + ball->getRadius() >= window->getWindowWidth()) {
        ball->setDirX(-ball->getDirX()); // Rebond horizontal
    }
    if (ball->getPosY() - ball->getRadius() <= 0) {
        ball->setDirY(-ball->getDirY()); // Rebond en haut
    }

    // Collision avec la barre du joueur
    if (ball->isColliding(player)) {
        ball->setDirY(-ball->getDirY());
    }

    // Collision avec les briques
    for (auto it = bricks.begin(); it != bricks.end();) {
        auto brick = component->getEntity<Sprite>(*it);
        if (brick && ball->isColliding(brick)) {

            // Calculates which side was the brick touched
            float deltaLeft = std::abs((brick->getPosX() - ball->getPosX()) - ball->getRadius());
            float deltaRight = std::abs((brick->getPosX() + brick->getWidth() - ball->getPosX()) + ball->getRadius());
            float deltaTop = std::abs((brick->getPosY() - ball->getPosY()) - ball->getRadius());
            float deltaBottom = std::abs((brick->getPosY() + brick->getHeight() - ball->getPosY()) + ball->getRadius());

            if (deltaLeft < deltaTop && deltaLeft < deltaRight && deltaLeft < deltaBottom) {
                // Left collision
                ball->setDirX(-ball->getDirX());
            }
            else if (deltaRight < deltaTop && deltaRight < deltaLeft && deltaRight < deltaBottom) {
                // Right collision
                ball->setDirX(-ball->getDirX());
            }
            else if (deltaTop < deltaLeft && deltaTop < deltaRight && deltaTop < deltaBottom) {
                // Up collision
                ball->setDirY(-ball->getDirY());
            }
            else {
                // Down collision
                ball->setDirY(-ball->getDirY());
            }

            component->deleteEntity(*it);
            it = bricks.erase(it);
        }
        else {
            ++it;
        }
    }

    ball->move();

    if (inputManager->isKeyHeld(KeyCode::LEFT) && player->getPosX() > 0)
    {
		player->setDirX(-5);
        player->move();
    }
    if (inputManager->isKeyHeld(KeyCode::RIGHT) && player->getPosX() < window->getWindowWidth() - player->getWidth())
    {
        player->setDirX(5);
        player->move();
    }

    // Perdre si la balle tombe en bas
    if (ball->getPosY() - ball->getRadius() > window->getWindowHeight()) {
    
		// Remettre la balle en haut
		ball->setPosition(400, 500);
		ball->setDirX(3);
		ball->setDirY(-3);
    }
}
