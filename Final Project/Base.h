#pragma once
#include "Character.h"
class Base : public Character
{
public:
	Base(int x, int y) : Character(x, y, 64, 128, 1, "base.png", 500, 70, 120, 0) {

	}

	Projectile* shoot();

};

