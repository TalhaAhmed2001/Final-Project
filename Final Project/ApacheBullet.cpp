#include "ApacheBullet.h"

void ApacheBullet::Move()
{
	setX(0.99 * getX() - 1);
	setY(getY() + 2);

	animate();
	ifOut();

	animate();
}
