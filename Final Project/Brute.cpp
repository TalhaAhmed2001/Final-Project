#include "Brute.h"
#include "BruteBullet.h"
#include "Blood.h"

void Brute::Move() {
	if (getX() <= 700) {
		setAnimation(4);
	}
	else {
		setX(getX() - 1);
	}
	animate();
}

Projectile* Brute::shoot() {
	BruteBullet* bullet = new BruteBullet(getX()+60, getY()+100);
	//setCurrSprite(getAnimation());
	// animate();
	return bullet;
}

Particle* Brute::getParticle() {
	Blood* particle = new Blood(getX(), getY(), getSpriteSize());
	return particle;
}
