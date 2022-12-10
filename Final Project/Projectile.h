#pragma once
#include "GameObject.h"
class Projectile : public GameObject
{
private:
	int AoE;
	int damage;
public:
	Projectile(int x, int y, int img, int spr, int aoe, int dmg, int ani, string p) :
		GameObject(x, y, img, spr, ani, p) {
		damage = dmg;
		AoE = aoe;
	}

	void setAoE(int aoe);
	void setDamage(int d);
	
	int getAoE();
	int getDamage();
	
};

