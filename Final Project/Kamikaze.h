#pragma once
#include "Character.h"
#include "KamikazeBullet.h"
class Kamikaze : public Character
{
public:
	Kamikaze(int x, int y) : Character(x,y, 32, 64, 2, "sprites/kamikaze.png", 10, 60, 55,5000) {

	}

	void Move();
	KamikazeBullet* shoot();
};

