#pragma once
#include "Particle.h"
class Explosion : public Particle
{
public:
	Explosion(int x, int y, int spr, string p) : Particle(x, y, 32, spr, 4, p) {

	}


};

