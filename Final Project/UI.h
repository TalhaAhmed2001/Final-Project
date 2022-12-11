#pragma once
#include "GameObject.h"
class UI : public GameObject
{
public:
	int val;
	UI(int x, int y, string p, int v) : GameObject(x, y, 64, 64, 1, p) {
		val = v;
	}
	
	void setVal(int v);
	int getVal();
	void incVal();
	void decVal();
};

