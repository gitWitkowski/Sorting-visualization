#pragma once
#include <iostream>
//	sleep
#include <chrono>
#include <thread>
//

struct SortingElement {
		SortingElement(int);
		bool operator<(const SortingElement&);
		int _value;
		int r;
		int g;
		int b;
};

SortingElement getNewRandomElement(int);