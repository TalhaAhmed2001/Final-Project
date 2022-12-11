#include "UI.h"

int UI::getVal() {
	return val;
}

void UI::incVal(int v)
{
	val = (getVal() + v);
	if (getVal() > max_val) {
		val = max_val;
	}
}

void UI::decVal()
{
	val = (getVal() - 1);
	if (getVal() < 0) {
		val = 0;
	}
}

