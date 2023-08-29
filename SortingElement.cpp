#include "SortingElement.h"

SortingElement::SortingElement(int value) : _value{value} {}

bool SortingElement::operator<(const SortingElement& obj) {

	std::chrono::milliseconds timespan(1); // or whatever

	std::this_thread::sleep_for(timespan);

	return (_value < obj._value);
}

SortingElement getNewRandomElement(int max) {
	int val = (rand() % max) + 1;
	SortingElement temp(val);
	return temp;
}