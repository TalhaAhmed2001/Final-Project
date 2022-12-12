#pragma once
#include "Projectile.h"
class BossBoom : public Projectile
{
public:
	BossBoom(int x, int y) : Projectile(x, y, 64, 64, 64, 50, 5, "sprites/BossBoom.png") {

	}

	void Move();
	Particle* getParticle();
};

