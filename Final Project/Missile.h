#pragma once
#include "Projectile.h"
class Missile : public Projectile
{
public:
	Missile() : Projectile(2, 80, 64, 96, 100, 50, 3, "sprites/Missile.png") {

	}

	void Move();
};

