#pragma once
#include <iostream>
#include <wx/colour.h>

struct SortingElement {
		SortingElement(int, wxColor);
		SortingElement(int);
		void SetColorRed();
		void SetColorGreen();
		void SetColorBlue();
		void SetColorWhite();
		int _value;
		mutable wxColor _color;
};

SortingElement getNewRandomElement(int);

bool operator<(const SortingElement&, const SortingElement&);