#pragma once
#include "Character.h"
#include "ApacheBullet.h"
class Apache : public Character
{
public:
	ApacheBullet(int x, int y) : Projectile(x, y + 85, 16, 32, 20, 40, 2, "sprites/apachebullet.png") {
		setSFXPath("sfx/explosion.mp3");
	}

	void Move();
	Projectile* shoot();
	Particle* getParticle();
};

