#pragma once
#include "Character.h"
class Infantry : public Character
{
public:
	Infantry(int x, int y) : Character(x, y, 32, 64, 2, "sprites/infantry.png", 17, 40, 60, 750) {
		setSFXPath("sfx/shot.mp3");
	}

	void Move();
	Projectile* shoot();
	Particle* getParticle();
};

