#pragma once
#include "Projectile.h"
class ApacheBullet : public Projectile
{
public:
	ApacheBullet(int x, int y) : Projectile(x , y + 85, 16, 32, 20, 40, 2, "sprites/apachebullet.png") {

	}

	void Move();
	Particle* getParticle();
};


