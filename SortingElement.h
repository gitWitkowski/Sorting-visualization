#pragma once
#include <iostream>

class SortingElement {
	public:
		SortingElement(int);
	private:
		int _value;
		int r;
		int g;
		int b;
};

SortingElement getNewRandomElement(int);