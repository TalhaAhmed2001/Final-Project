#include "Missile.h"

void Missile::Move()
{
	setX(getX() + 15);
	animate();
}
