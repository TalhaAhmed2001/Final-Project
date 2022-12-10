#pragma once
#include "GameObject.h"
class Button : public GameObject
{
private:
	string text;
public:
	Button(int x, int y, string t) : GameObject(x, y, 64, 100, 1, "sprites/button.png") {
		text = t;
	}

	bool ifInside(int mouse_x, int mouse_y);
	string getText();
};

