#pragma once
#include "Projectile.h"
class InfantryBullet : public Projectile
{
public:
	InfantryBullet(int X, int Y) : Projectile(X, Y, 16, 16, 10, 10, 2, "infantrybullet.png") {

	}

	void Move();
};