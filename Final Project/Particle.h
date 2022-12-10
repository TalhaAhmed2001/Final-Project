#pragma once
#include "GameObject.h"
class Particle : public GameObject
{
private:
	int alpha = 255;
public:
	Particle(int x, int y, int img, int spr, int ani, string p) :
		GameObject(x, y, img, spr, ani, p) {

	}

	void decAlpha();
	void Move();
	int getAlpha();
	void animate();

};

