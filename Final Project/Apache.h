#pragma once
#include "Character.h"
#include "ApacheBullet.h"
class Apache : public Character
{
public:
	Apache(int x, int y) : Character(x,y, 64, 128, 2, "sprites/apache.png", 100, 120, 120, 3000) {

	}

	void Move();
	Projectile* shoot();
	Particle* getParticle();
};

