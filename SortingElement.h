#pragma once
#include <iostream>

struct SortingElement {
		SortingElement(int);
		int _value;
		int r;
		int g;
		int b;
};

SortingElement getNewRandomElement(int);