#include "InfantryBullet.h"

void InfantryBullet::Move() {
	setX(getX() - 10);

	ifOut();

	animate();
}
