#include "SupplyDrop.h"

void SupplyDrop::Move() {
	if (getY() < 350) {
		setY(getY() + 4);
		setAngle(-5 + rand() % 5);
	}
	else {
		setCurrSprite(1);
	}
}

int SupplyDrop::getType()
{
	return type;
}
