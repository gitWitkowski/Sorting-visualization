#pragma once
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include "SortingElement.h"

/// class representing array with elements to sort
class SortingArray {
	public:
		SortingArray(double*);
		int GetValue(size_t) const;
		wxColor GetColor(size_t) const;
		SortingElement& operator[](size_t);
		size_t size() const;
		void clear();
		void push_back(const SortingElement);
		typename std::vector<SortingElement>::iterator begin();
		typename std::vector<SortingElement>::iterator end();
		void swap(size_t, size_t);

	private:
		std::vector<SortingElement> myArray;
		double* delayTime;
};