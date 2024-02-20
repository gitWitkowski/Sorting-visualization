#pragma once
#include <iostream>
#include <wx/colour.h>

struct SortingElement {
	SortingElement(int, wxColor);
	SortingElement(int value = 0);
	bool operator<(const SortingElement&) const;
	bool operator>(const SortingElement&) const;
	bool operator<=(const SortingElement&) const;
	bool operator>=(const SortingElement&) const;
	SortingElement& operator=(const SortingElement&);
	void setColorWhite() const;
	void setColorRed() const;
	void setColorGreen() const;
	void setColorBlue() const;
	void setColorOrange() const;
	void setColorYellow() const;

	int _value;
	mutable wxColor _color;
};
