#pragma once
#include "Projectile.h"
class Airstrike : public Projectile
{
public:
	Airstrike(int x, int y) : Projectile(x, y, 64, 128, 150, 500, 2, "sprites/airstrikemissiles.png") {
		setSFXPath("sfx/explosion.mp3");
	}

	void Move();
	Particle* getParticle();
};

