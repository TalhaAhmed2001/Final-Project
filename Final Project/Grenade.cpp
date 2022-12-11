#include "Grenade.h"

void Grenade::Move() {
	if (getY()<380) {
		setX(getX() + 4);
		setY(getY() + 2);
		setAngle(getAngle() + rand() % 20);
	}
	
}