#pragma once
#include "Character.h"
class SupplyDrop : public Character
{
private:
	int type;
public:
	SupplyDrop(string p) : Character(400 + rand() % 300, 20, 64, 64,2,p, 10, 64, 64, 1) {

	}

	void Move();
};

