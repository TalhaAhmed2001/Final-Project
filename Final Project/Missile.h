#pragma once
#include "Projectile.h"
class Missile : public Projectile
{
public:
	Missile() : Projectile(2, 50, 64, 32, 10, 50, 2, "sprites/tankbullet.png") {

	}

	void Move();
};

