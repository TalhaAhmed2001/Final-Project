#include "Boss.h"
#include "BossBoom.h"
#include "BossBullet.h"

void Boss::Move() {
	if (getX() > 1100) {
		setX(getX() - 1);
	}
	animate();
}

Projectile* Boss::shoot() {

	int x = rand() % 8;
	
	Projectile* projectile =  nullptr;

	if (x == 6) {
		projectile = new BossBoom(getX(), getY() + getSpriteSize() / 2);
		setSFXPath("sfx\BossCannon.wav");
	}
	else{
		projectile = new BossBullet(getX() +getSpriteSize() / 2, getY());
		setSFXPath("sfx/shot.mp3");
	}
	setCurrSprite(2);
	return projectile;
}

