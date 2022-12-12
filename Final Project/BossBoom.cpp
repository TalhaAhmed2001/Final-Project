#include "BossBoom.h"
#include "Explosion.h"

void BossBoom::Move() {
	setX(getX() - 10);
	animate();
}

Particle* BossBoom::getParticle() {
	Explosion* temp = new Explosion(getX(), getY(), getSpriteSize(), "sprites/Explosion1.png");
	return temp;
}