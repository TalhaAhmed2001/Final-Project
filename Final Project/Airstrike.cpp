#include "Airstrike.h"
#include "Explosion.h"

void Airstrike::Move()
{
	if (getY() < 300) {
		setY(getY() + 20);
		animate();
	}
	else {
		kill();
	}
}

Particle* Airstrike::getParticle()
{
	Explosion* particle = new Explosion(getX() - 32, getY() - 32, getSpriteSize() + 64, "sprites/explosion2.png");
	return particle;
}
