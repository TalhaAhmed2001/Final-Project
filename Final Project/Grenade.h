#pragma once
#include "Projectile.h"
class Grenade : public Projectile
{
public:

	Grenade() : Projectile(100, 220, 64, 32, 64, 30, 1, "sprites/grenade.png") {
		setSFXPath("sfx/explosion.mp3");

	}

	void Move();
	Particle* getParticle();
};

