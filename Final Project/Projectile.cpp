#include "Projectile.h"
using namespace std;

void Projectile::setAoE(int aoe) {
	AoE = aoe;
}

void Projectile::setDamage(int d) {
	damage = d;
}

int Projectile::getAoE() {
	return AoE;
}

int Projectile::getDamage() {
	return damage;
}

