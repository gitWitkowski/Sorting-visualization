#include "SortingElement.h"

SortingElement::SortingElement(int value) : _value{value} {}

SortingElement getNewRandomElement(int max) {
	int val = (rand() % max) + 1;
	SortingElement temp(val);
	return temp;
}