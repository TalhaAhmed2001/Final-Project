#include "TankBullet.h"

void TankBullet::Move() {
	setX(getX() - 10);

	ifOut();
}