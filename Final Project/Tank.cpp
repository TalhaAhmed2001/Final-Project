#include "Tank.h"
#include "TankBullet.h"
#include "Explosion.h"

void Tank::Move() {
	if (getX() > 900) {
		setX(getX() - 1);
	}
	animate();
}

Projectile* Tank::shoot() {
	TankBullet* bullet = new TankBullet(getX(), getY() + 20);
	return bullet;
}

Particle* Tank::getParticle()
{
	Explosion* particle = new Explosion(getX(), getY(), getSpriteSize(), "sprites/explosion1.png");
	return particle;
}