#include "Character.h"

int Character::getMaxHP() {
	return max_health;
}

int Character::getHealth() {
	return health;
}

int Character::getHitboxX() {
	return hitbox_x;
}

int Character::getHitboxY() {
	return hitbox_y;
}

int Character::getFreq()
{
	return shoot_freq;
}

void Character::decHealth(int dmg) {
	health -= dmg;
	if (health <= 0) {
		kill();
	}
}

void Character::incHealth(int h) {
	health += h;
	if (health > max_health) {
		health = max_health;
	}
}

Projectile* Character::shoot()
{
	return nullptr;
}

Particle* Character::getParticle()
{
	return nullptr;
}

Projectile* Character::shoot(int x, int y)
{
	return nullptr;
}

bool Character::detCollision(int x, int y, int aoe, int size) {
	
	int a1 = x + size / 2 - aoe / 2;
	int a2 = x + size / 2 + aoe / 2;
	int b1 = y + size / 2 + aoe / 2;
	int b2 = y + size / 2 - aoe / 2;

	int x1 = getX() + getImageSize() / 2 - getHitboxX() / 2;
	int x2 = getX() + getImageSize() / 2 + getHitboxX() / 2;
	int y1 = getY() + getImageSize() / 2 + getHitboxY() / 2;
	int y2 = getY() + getImageSize() / 2 - getHitboxY() / 2;

	if (a1 > x1 && a1 < x2 && b2 < y1 && b2 > y2) {
		return true;
	}
	if (a1 > x1 && a1 < x2 && b1 < y1 && b1 > y2) {
		return true;
	}
	if (a2 > x1 && a2 < x2 && b2 < y1 && b2 > y2) {
		return true;
	}
	if (a2 > x1 && a2 < x2 && b1 < y1 && b1 > y2) {
		return true;
	}
	if (x1 > a1 && x1 < a2 && y2 > b2 && y2 < b1) {
		return true;
	}
	if (x1 > a1 && x1 < a2 && y1 > b2 && y1 < b1) {
		return true;
	}
	if (x2 > a1 && x2 < a2 && y2 > b2 && y2 < b1) {
		return true;
	}
	if (x2 > a1 && x2 < a2 && y1 > b2 && y1 < b1) {
		return true;
	}

	return false;

}