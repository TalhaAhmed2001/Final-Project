#include "Grenade.h"
#include "Explosion.h"

void Grenade::Move() {
	if (getY()<380) {
		setX(getX() + 4);
		setY(getY() + 2);
		setAngle(getAngle() + rand() % 20);
	}
	
}

Particle* Grenade::getParticle() {
	Explosion* particle = new Explosion(getX(), getY(), getSpriteSize() + 32, "sprites/explosion3.png");
	return particle;
}