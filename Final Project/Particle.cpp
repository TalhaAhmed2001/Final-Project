#include "Particle.h"

void Particle::decAlpha()
{
    alpha = alpha - rand() % 4;
    if (alpha <= 0) {
        kill();
    }
}

void Particle::Move()
{
    decAlpha();
    animate();
}

int Particle::getAlpha()
{
    return alpha;
}

void Particle::animate() {
    if (getCurrSprite() + 0.1 < getAnimation()) {
        setCurrSprite(getCurrSprite() + 0.1);
    }
}
