#include "Turret.h"
#include "TurretBullet.h"

void Turret::Move(int x, int y)
{
	int target_x = x;
	int target_y = y;
	double del_x = (double)target_x - (double)(getX() + getImageSize() / 2);
	double del_y = (double)target_y - (double)(getY() + getImageSize() / 2);

	double degree = atan2(del_y, del_x) * (180.0 / 3.141592653589793238463);
	if (degree < -15) {
		setAngle(-15);
	}
	else if (degree > 15) {
		setAngle(15);
	}
	else {
		setAngle(degree);
	}
	animate();
}

void Turret::animate() {
	
	if (getCurrSprite() - (int)getCurrSprite() == 0) {
		setCurrSprite(0);
	}
	else {
		setCurrSprite(getCurrSprite() + 0.1);
	}

}

Projectile* Turret::shoot(int x, int y){

	TurretBullet* bullet = new TurretBullet(getX() + getSpriteSize() - 60, getY() + getSpriteSize() / 2 - 20, x, y);
	setCurrSprite(0.8);
	return bullet;
}
