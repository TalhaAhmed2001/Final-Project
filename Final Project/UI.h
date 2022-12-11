#pragma once
#include "GameObject.h"
class UI : public GameObject
{
private:
	int val;
	int max_val;
public:
	UI(int x, int y, string p, int v) : GameObject(x, y, 64, 64, 1, p) {
		val = v;
		max_val = v;
	}
	
	int getVal();
	void incVal(int v);
	void decVal();
};

