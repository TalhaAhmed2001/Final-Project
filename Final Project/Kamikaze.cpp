#include "Kamikaze.h"

void Kamikaze::Move()
{
    setX(getX() - 3);
    setY(0.0005*pow(getX() - 1200,2) + 20);
    animate();
}

KamikazeBullet* Kamikaze::shoot()
{
    KamikazeBullet* bullet = new KamikazeBullet(getX(), getY());
    kill();
    return bullet;
}
