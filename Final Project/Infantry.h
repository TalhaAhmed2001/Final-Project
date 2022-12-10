#pragma once
#include "Character.h"
class Infantry : public Character
{
public:
	Infantry(int x, int y) : Character(x,y, 32, 64, 2, "infantry.png", 20, 40, 60, 750) {

	}

	void Move();
	Projectile* shoot();
};

