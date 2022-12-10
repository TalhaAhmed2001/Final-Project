#include "Apache.h"
#include "Explosion.h"

void Apache::Move()
{
    if (getX() > 500){
        setX(getX() - 1);
        setY(50 + 15 * sin(0.2 * getX()));
    }
    animate();
}

Projectile* Apache::shoot()
{
    ApacheBullet* bullet = new ApacheBullet(getX(), getY());
    return bullet;
}

Particle* Apache::getParticle()
{
    Explosion* particle = new Explosion(getX(), getY(), getSpriteSize(), "explosion2.png");
    return particle;
}
