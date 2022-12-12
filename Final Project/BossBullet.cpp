#include "BossBullet.h"
#include "Explosion.h"

void BossBullet::Move()
{
	setX(getX()-7);
	setY(getY() + 1);
	animate();
}

Particle* BossBullet::getParticle() {
	Explosion* temp = new Explosion(getX(), getY(), getSpriteSize(), "sprites/Explosion3.png");
	return temp;
}
