#pragma once
#include "Character.h"
class Turret : public Character
{
public:
	Turret(int x, int y) : Character(x, y, 128, 256, 1, "sprites/turret.png", 500, 200, 200, 0) {

	}

	void Move(int x, int y);
	void animate();
	Projectile* shoot(int x, int y);
};

