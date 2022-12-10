#include "Infantry.h"
#include "InfantryBullet.h"

void Infantry::Move() {
	setX(getX() - 1 - rand() % 2);
	animate();
	if (getX() < 700) {
		kill();
	}
}

Projectile* Infantry::shoot() {
	InfantryBullet* bullet = new InfantryBullet(getX(), getY()+10);
	setCurrSprite(getAnimation());
	return bullet;
}