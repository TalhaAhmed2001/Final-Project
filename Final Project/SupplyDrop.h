#pragma once
#include "Character.h"
class SupplyDrop : public Character
{
private:
	int type;
public:
	SupplyDrop(int t, string p) : Character(550 + rand() % 500, 20, 64, 64,2,p, 1, 64, 64, 1) {
		type = t;
	}

	void Move();
	int getType();
};

