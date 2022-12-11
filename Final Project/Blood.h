#pragma once
#include "Particle.h"
class Blood : public Particle
{
public:
	Blood(int x, int y, int spr) : Particle(x, y, 32, spr, 3, "sprites/blood.png") {

	}
};

