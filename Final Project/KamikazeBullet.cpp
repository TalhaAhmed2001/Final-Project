#include "KamikazeBullet.h"
#include "Explosion.h"

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

Particle* KamikazeBullet::getParticle() {
	Explosion* particle = new Explosion(getX() - 32, getY() - 32, getSpriteSize() + 64, "sprites/explosion3.png");
	return particle;
}