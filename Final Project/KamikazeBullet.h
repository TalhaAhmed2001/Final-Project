#pragma once
#include "Projectile.h"
class KamikazeBullet : public Projectile
{
public:
	KamikazeBullet(int x, int y) : Projectile(x, y, 32, 48, 50, 60, 2, "sprites/kamikazerocket.png") {
		
	}

	void Move();
	Particle* getParticle();
};

