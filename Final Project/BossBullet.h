#pragma once
#include "Projectile.h"
class BossBullet : public Projectile
{
public:
	BossBullet(int x, int y) : Projectile(x, y, 32, 32, 30,20, 3, "sprites/BossBullet.png") {

	}

	void Move();

	Particle* getParticle();

};

