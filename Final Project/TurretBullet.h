#pragma once
#include "Projectile.h"
class TurretBullet : public Projectile
{
private:
	float x_vec = 0;
	float y_vec = 0;
public:
	TurretBullet(int x, int y, int mouse_x, int mouse_y) : Projectile(x, y, 16, 16, 25, 10, 1, "sprites/turretbullet.png") {
		setAngleVec(mouse_x, mouse_y);
	}

	void setXvec(float x);
	void setYvec(float y);
	void setAngleVec(int x, int y);

	void Move();

	float getXvec();
	float getYvec();

};

