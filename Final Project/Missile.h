#pragma once
#include "Projectile.h"
class Missile : public Projectile
{
public:
	Missile() : Projectile(2, 350, 64, 96, 100, 200, 3, "sprites/Missile.png") {
		setSFXPath("sfx/explosion.mp3");
	}

	void Move();
};

