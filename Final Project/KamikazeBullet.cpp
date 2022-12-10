#include "KamikazeBullet.h"

void KamikazeBullet::Move() {
	
	if (getX() >= 210) {
		setX(getX() - rand() % 2 - 3);
	}
	
	if (getY() <= 355) {
		setY(getY() + rand() % 2 + 1);
	}
	
	ifOut();
	
	setAngle(atan2(360 - getY(), 200 - getX()) * (180.0 / 3.141592653589793238463)+180);
	animate();
}