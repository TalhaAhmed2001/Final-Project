#include "Infantry.h"
#include "InfantryBullet.h"
#include "Blood.h"
#include "Explosion.h"

void Infantry::Move() {
	if (getX() > 350) {
		setX(getX() - 2 - rand() % 2);
	}
	animate();
}

Projectile* Infantry::shoot() {
	InfantryBullet* bullet = new InfantryBullet(getX(), getY()+10);
	setCurrSprite(getAnimation());
	return bullet;
}

Particle* Infantry::getParticle() {
	if (getX() < 500) {
		Explosion* particle = new Explosion(getX(), getY(), getSpriteSize(),"sprites/explosion3.png");
		return particle;
	}
	Blood* particle = new Blood(getX(), getY(), getSpriteSize());
	return particle;
}