#include "Button.h"

bool Button::ifInside(int mouse_x, int mouse_y) {

	if (mouse_x > getX() && mouse_x < getX() + getSpriteSize()*2 && mouse_y > getY() && mouse_y < getY() + getSpriteSize()) {
		setCurrSprite(getAnimation());
		return true;
	}
	else {
		setCurrSprite(0);
		return false;
	}
}

string Button::getText() {
	return text;
}