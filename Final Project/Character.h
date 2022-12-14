#pragma once
#include "GameObject.h"
#include "Projectile.h"
#include "Particle.h"
using namespace std;

class Character : public GameObject
{
private:
	int health;
	int max_health;
	int hitbox_x;
	int hitbox_y;
	int shoot_freq;
public:
	Character(int X, int Y, int img, int spr, int ani, string p, int heal, int h_x, int h_y, int f) :
		GameObject(X, Y, img, spr, ani, p) {
		health = heal;
		max_health = heal;
		hitbox_x = h_x;
		hitbox_y = h_y;
		shoot_freq = f;
	}

	int getMaxHP();
	int getHealth();
	int getHitboxX();
	int getHitboxY();
	int getFreq();

	void decHealth(int dmg);
	void incHealth(int h);

	virtual Projectile* shoot();
	virtual Projectile* shoot(int x, int y);

	virtual Particle* getParticle();

	bool detCollision(int x, int y, int hitbox, int size);
	//virtual Particle* getParticle() {}
};

