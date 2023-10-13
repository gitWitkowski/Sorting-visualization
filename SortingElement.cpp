#include "SortingElement.h"

SortingElement::SortingElement(int value, wxColor color) : _value{ value }, _color{ color } {}

SortingElement::SortingElement(int value) : SortingElement{value, wxColor(255,255,255)} {}

bool SortingElement::operator<(const SortingElement& o) const{
	return _value < o._value;
}

bool SortingElement::operator>(const SortingElement& o) const {
	return _value > o._value;
}

bool SortingElement::operator<=(const SortingElement& o) const {
	return _value <= o._value;
}

bool SortingElement::operator>=(const SortingElement& o) const {
	return _value >= o._value;
}

void SortingElement::SetColorWhite() const {
	_color = wxColor(255, 255, 255);
}

void SortingElement::SetColorRed() const {
	_color = wxColor(255, 0, 0);
}

void SortingElement::SetColorGreen() const {
	_color = wxColor(0, 255, 0);
}

void SortingElement::SetColorBlue() const {
	_color = wxColor(0, 0, 255);
}