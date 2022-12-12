#pragma once
#include "Projectile.h"
class TankBullet : public Projectile
{
public:
	TankBullet(int x, int y) : Projectile(x, y, 16, 16, 12, 25, 1, "sprites/tankbullet.png") {
		setSFXPath("sfx/explosion.mp3");
	}

	void Move();
};

