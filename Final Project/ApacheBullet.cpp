#include "ApacheBullet.h"
#include "Explosion.h"

void ApacheBullet::Move()
{
	setX(0.99 * getX() - 1);
	setY(getY() + 2);

	animate();
	ifOut();

	animate();
}

Particle* ApacheBullet::getParticle() {
	Explosion* particle = new Explosion(getX() - 32, getY() - 32, getSpriteSize() + 64, "sprites/explosion3.png");
	return particle;
}
