#pragma once
#include "Character.h"
class Base : public Character
{
public:
	Base(int x, int y) : Character(x, y, 128, 256, 1, "sprites/base.png", 1000, 250, 250, 0) {

	}

};

