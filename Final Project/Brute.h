#pragma once
#include "Character.h"
class Brute : public Character
{
public:
	Brute(int x, int y) : Character(x,y, 88, 194, 4, "allen.png", 40, 140, 140,500) {

	}

	void Move();
	Projectile* shoot();
	
};

