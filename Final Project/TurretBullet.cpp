#include "TurretBullet.h"

void TurretBullet::Move() {
	setX(getX() + 2 * getXvec());
	setY(getY() + 2 * getYvec());

	ifOut();
}

void TurretBullet::setXvec(float x) {
	x_vec = x;
}

void TurretBullet::setYvec(float y) {
	y_vec = y;
}

float TurretBullet::getXvec(){
	return x_vec;
}

float TurretBullet::getYvec() {
	return y_vec;
}

void TurretBullet::setAngleVec(int x, int y) {

	int target_x = x;
	int target_y = y;
	double del_x = (double)target_x - (double)getX();
	double del_y = (double)target_y - (double)getY();

	double degree = atan2(del_y, del_x) * (180.0 / 3.141592653589793238463);

	if (degree < -15) {
		setAngle(75);
	}
	else if (degree > 15) {
		setAngle(105);
	}
	else {
		setAngle(degree + 90);
	}
	//setAngle(degree + 90);

	setXvec(10 * (sin((getAngle()) / (180.0 / 3.141592653589793238463))));
	setYvec(-20 * (cos((getAngle()) / (180.0 / 3.141592653589793238463))));
}