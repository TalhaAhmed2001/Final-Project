#pragma once
#include "Character.h"
class Boss : public Character
{
public:
	Boss() : Character(1350, 200, 256, 312, 4, "sprites/Boss.png", 3000, 250, 250, 300) {

	}

	void Move();
	Projectile* shoot();
};

