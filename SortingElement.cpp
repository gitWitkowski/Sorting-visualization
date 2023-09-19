#include "SortingElement.h"

SortingElement::SortingElement(int value, wxColor color) : _value{ value }, _color{ color } {}

SortingElement::SortingElement(int value) : SortingElement{value, wxColor(255,255,255)} {}

SortingElement getNewRandomElement(int max) {
	int val = (rand() % max) + 1;
	SortingElement temp(val, wxColor(255, 255, 255));
	return temp;
}

void SortingElement::SetColorRed() { _color = wxColor(255, 0, 0);  }

void SortingElement::SetColorGreen() { _color = wxColor(0, 255, 0); }

void SortingElement::SetColorBlue() { _color = wxColor(0, 0, 255); }

void SortingElement::SetColorWhite() { _color = wxColor(255, 255, 255); }

bool operator<(const SortingElement& o1, const SortingElement& o2) {
	return o1._value < o2._value;
}