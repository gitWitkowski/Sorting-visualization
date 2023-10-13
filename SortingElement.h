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
		void SetColorWhite() const;
		void SetColorRed() const;
		void SetColorGreen() const;
		void SetColorBlue() const;

		int _value;
		mutable wxColor _color;
};
