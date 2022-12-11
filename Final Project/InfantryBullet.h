#pragma once
#include "Projectile.h"
class InfantryBullet : public Projectile
{
public:
	InfantryBullet(int X, int Y) : Projectile(X, Y, 16, 16, 10, 5, 2, "sprites/infantrybullet.png") {

	}

	void Move();
};