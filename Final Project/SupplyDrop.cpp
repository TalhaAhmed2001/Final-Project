#include "SupplyDrop.h"

void SupplyDrop::Move() {
	if (getY() < 300) {
		setY(getY() + 10);
		setAngle(-10 + rand() % 20);
	}
}