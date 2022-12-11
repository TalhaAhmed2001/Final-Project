#include "UI.h"

void UI::setVal(int v) {
	val = v;
}

int UI::getVal() {
	return val;
}

void UI::incVal()
{
	setVal(getVal() + 1);
	if (getVal() > 10) {
		setVal(10);
	}
}

void UI::decVal()
{
	setVal(getVal() - 1);
	if (getVal() < 0) {
		setVal(0);
	}
}

