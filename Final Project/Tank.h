#pragma once
#include "Character.h"
class Tank : public Character
{
public:
	Tank(int x, int y) : Character(x, y, 64, 128, 2, "tank.png", 200, 120, 120, 2000) {

	}

	void Move();
	Projectile* shoot();
	Particle* getParticle();
};

