#include "BruteBullet.h"


void BruteBullet::Move() {
	setX(getX() - 6);

	ifOut();
}
