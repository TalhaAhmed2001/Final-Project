#pragma once
#include "Projectile.h"
class BruteBullet :	public Projectile
{
public:
	BruteBullet(int X, int Y) : Projectile(X, Y, 16, 16, 16, 15, 2, "sprites/infantrybullet.png") {

	}

	void Move();
	
};

