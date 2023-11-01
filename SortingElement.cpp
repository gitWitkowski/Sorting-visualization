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

SortingElement &SortingElement::operator=(const SortingElement& obj) {
	_value = obj._value;
	// no _color assignment
	return *this;
}

void SortingElement::setColorWhite() const {
	_color = wxColor(255, 255, 255);
}

void SortingElement::setColorRed() const {
	_color = wxColor(255, 0, 0);
}

void SortingElement::setColorGreen() const {
	_color = wxColor(0, 255, 0);
}

void SortingElement::setColorBlue() const {
	_color = wxColor(0, 0, 255);
}