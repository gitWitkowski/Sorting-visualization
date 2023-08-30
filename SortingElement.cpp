#include "SortingElement.h"

SortingElement::SortingElement(int value, wxColor color) : _value{ value }, _color{ color } {}

SortingElement getNewRandomElement(int max) {
	int val = (rand() % max) + 1;
	SortingElement temp(val, wxColor(210, 102, 11));
	return temp;
}

bool operator<(const SortingElement& o1, const SortingElement& o2) {
	return o1._value < o2._value;
}