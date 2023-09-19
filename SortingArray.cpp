#include "SortingArray.h"

SortingArray::SortingArray(double *delay) : delayTime{delay} {}

int SortingArray::GetValue(size_t pos) const {
	std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(*delayTime)));
	return myArray[pos]._value;
}
wxColor SortingArray::GetColor(size_t pos) const {
	return myArray[pos]._color;
}
SortingElement& SortingArray::operator[](size_t pos) {
	return myArray[pos];
}

size_t SortingArray::size() const {
	return myArray.size();
}

void SortingArray::push_back(const SortingElement elem) {
	myArray.push_back(elem);
}

void SortingArray::clear() {
	myArray.clear();
}

typename std::vector<SortingElement>::iterator SortingArray::begin() {
	return myArray.begin();
}
typename std::vector<SortingElement>::iterator SortingArray::end() {
	return myArray.end();
}

void SortingArray::swap(size_t pos1, size_t pos2) {
	std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(*delayTime)));
	std::swap(myArray[pos1], myArray[pos2]);
}