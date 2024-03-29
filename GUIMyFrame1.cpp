﻿#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent), _maxElemValue{ m_slider_Num_of_Elem->GetValue()}, _delayTimeInUs{10000}
{
	m_ComparisonsNum->SetLabel(std::to_string(SortingElement::comparisonNum));
	UpdateTab();
	// 60 fsp (1000 ms / 60 frames)
	m_Timer.Start(1000 / 60);
	ControlsOnStop();
}

void GUIMyFrame1::drawPanelOnSize(wxSizeEvent& event)
{
	// TODO: Implement drawPanelOnSize
	std::string text = std::to_string(drawPanel->GetSize().x);
	//m_staticText2->SetLabel(text);
}


void GUIMyFrame1::drawPanelOnPaint(wxPaintEvent& event)
{
	wxClientDC dc1(drawPanel);
	wxBufferedDC dc(&dc1);

	dc.Clear();

	int w, h;

	drawPanel->GetSize(&w, &h);

	int tempWidth = w / _tab.size();
	double unitHeight = static_cast<double>(h) / _maxElemValue;

	int shift = GetShift(w);

	for (int i = 0; i < _tab.size(); i++) {
		wxBrush tempBrush(_tab[i]._color);
		wxPen tempPen(_tab[i]._color, 0);

		dc.SetBrush(tempBrush);
		dc.SetPen(tempPen);

		dc.DrawRectangle(
			wxRect(
				shift + i * tempWidth, h - static_cast<int>(unitHeight * _tab[i]._value),
				tempWidth, static_cast<int>(unitHeight * _tab[i]._value)
			));
	}
}

void GUIMyFrame1::m_choice_SortTypeOnChoice(wxCommandEvent& event)
{
	// TODO: Implement m_choice_SortTypeOnChoice

}

void GUIMyFrame1::m_slider_Num_of_ElemOnScroll(wxScrollEvent& event)
{
	// TODO: Implement m_slider_Num_of_ElemOnScroll
	_maxElemValue = _tab.size();
	UpdateTab();
}

void GUIMyFrame1::m_button_SortOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_SortOnButtonClick

	ControlsOnStart();

	switch (m_choice_SortType->GetSelection())
	{
	case BUBBLE_SORT: // 0
		_bgThread = std::jthread(&GUIMyFrame1::BubbleSort, this);
		break;

	case INSERTION_SORT: // 1
		_bgThread = std::jthread(&GUIMyFrame1::InsertionSort, this);
		break;

	case SELECTION_SORT: // 2
		_bgThread = std::jthread(&GUIMyFrame1::SelectionSort, this);
		break;

	case MERGE_SORT: // 3
		_bgThread = std::jthread(&GUIMyFrame1::MergeSort, this, 0, _tab.size() - 1);
		break;

	case HEAP_SORT: // 4
		_bgThread = std::jthread(&GUIMyFrame1::HeapSort, this);
		break;

	case STD_SORT: // 5
		_bgThread = std::jthread(&GUIMyFrame1::StdSort, this);
		break;

	case QUICK_SORT_HOARE: // 6
		_bgThread = std::jthread(&GUIMyFrame1::QuickSortHoare, this, 0, _tab.size() - 1);
		break;

	case QUICK_SORT_LOMUTO: // 7
		_bgThread = std::jthread(&GUIMyFrame1::QuickSortLomuto, this, 0, _tab.size() - 1);
		break;

	case SHELL_SORT: // 8
		_bgThread = std::jthread(&GUIMyFrame1::ShellSort, this);
		break;

	case COCKTAIL_SHAKER_SORT: // 9
		_bgThread = std::jthread(&GUIMyFrame1::CocktailShakerSort, this);
		break;

	case ODD_EVEN_SORT: // 10
		_bgThread = std::jthread(&GUIMyFrame1::OddEvenSort, this);
		break;

	default:
		ControlsOnStop();
		break;
	}

	// detaching thread
	if(_bgThread.joinable())
		_bgThread.detach();
}

void GUIMyFrame1::m_button_ShuffleOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_ShuffleOnButtonClick
	UpdateTab();

}


void GUIMyFrame1::m_button_StopOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_StopOnButtonClick
	std::stop_token st = _bgThread.get_stop_token();
	std::stop_callback sc(st, [this] { /*DoDelay();*/ UpdateTab(); ControlsOnStop(); });

	_bgThread.request_stop();
}


void GUIMyFrame1::UpdateTab()
{
	_tab.clear();

	int tabSize = m_slider_Num_of_Elem->GetValue();

	// https://en.cppreference.com/w/cpp/algorithm/random_shuffle
	std::random_device rd;
	std::mt19937 g(rd());
	//
	std::uniform_int_distribution<std::mt19937::result_type> distrTabSize(0, tabSize - 1); // returns number between 0 and (TabSize - 1)
	std::uniform_int_distribution<std::mt19937::result_type> distrCloseElement(0, 2); // return number between 0 and 3

	switch (m_shuffleType->GetSelection())
	{
	case RANDOM_SHUFFLE:
	{
		for (int i = 0; i < tabSize; i++)
			_tab.push_back(SortingElement(i + 1));

		std::shuffle(_tab.begin(), _tab.end(), g);
		break;
	}

	case NEARLY_SORTED:
	{
		for (int i = 0; i < tabSize; i++)
			_tab.push_back(SortingElement(i + 1));

		for (int i = 0; i < tabSize; i++) {
			int indx1 = distrTabSize(g); // random index of first element to swap
			int indx2 = indx1 + distrCloseElement(g); // random index of second element to swap, not farther than value returned by distrCloseElement

			while (indx2 < 0 || indx2 >= tabSize) indx2 = indx1 + distrCloseElement(g); // generate new index if previous is invalid

			std::swap(_tab[indx1], _tab[indx2]); // swap two elements (they are close to each other)
		}
		break;
	}

	case MANY_DUPLICATES:
	{
		// array FewUnique containing 6 numbers used later as values for _tab 
		int FewUnique[] = {
			// 5 random numbers in range from 1 to TabSize
			static_cast<int>(distrTabSize(g) + 1),
			static_cast<int>(distrTabSize(g) + 1),
			static_cast<int>(distrTabSize(g) + 1),
			static_cast<int>(distrTabSize(g) + 1),
			static_cast<int>(distrTabSize(g) + 1),
			// 1 maximal value so that elements are always displayed nicely (correct scale)
			tabSize
		};
		std::uniform_int_distribution<std::mt19937::result_type> distrFewUnique(0, 5); // random index from 0 to 5 to get number from array FewUnique
		for (int i = 0; i < tabSize; i++)
			_tab.push_back(SortingElement(FewUnique[distrFewUnique(g)]));
		break;
	}

	case DESCENDING_ORDER:
	{
		for (int i = tabSize; i > 0; i--)
			_tab.push_back(SortingElement(i));
		break;
	}

	case ALREADY_SORTED:
	{
		for (int i = 0; i < tabSize; i++)
			_tab.push_back(SortingElement(i + 1));
		break;
	}

	default:
		break;
	}
}

int GUIMyFrame1::GetShift(int w) {
	int AllElemWidth = _tab.size() * int(w / _tab.size());
	return (w - AllElemWidth) / 2;
}

void GUIMyFrame1::ControlsOnStart() {
	m_slider_Num_of_Elem->Disable();
	m_button_Shuffle->Disable();
	m_button_Sort->Disable();
	m_button_Stop->Enable();
	SortingElement::comparisonNum = 0;
}

void GUIMyFrame1::ControlsOnStop() {
	m_slider_Num_of_Elem->Enable();
	m_button_Shuffle->Enable();
	m_button_Sort->Enable();
	m_button_Stop->Disable();
}

void GUIMyFrame1::BubbleSort() {
	std::stop_token st = _bgThread.get_stop_token();
	int size = _tab.size();
	for (int i = 0; i < size - 1 && !st.stop_requested(); i++) {
		for (int j = 0; j < size - i - 1 && !st.stop_requested(); j++) {
			// set colors
			_tab[j].setColorGreen();
			_tab[j + 1].setColorBlue();
			//
			DoDelay();
			if (_tab[j] > _tab[j + 1]) {
				std::swap(_tab[j], _tab[j + 1]);
				DoDelay();
			}
			// set colors
			_tab[j].setColorWhite();
			_tab[j + 1].setColorWhite();
			//
		}
	}
	ControlsOnStop();
}

void GUIMyFrame1::InsertionSort() {
	std::stop_token st = _bgThread.get_stop_token();
	// https://en.wikipedia.org/wiki/Insertion_sort

	for (int i = 0; i < _tab.size() && !st.stop_requested(); i++) {
		int j = i;
		_tab[i].setColorBlue();
		while (j > 0 && _tab[j-1] > _tab[j] && !st.stop_requested()) {
			_tab[i].setColorBlue();
			_tab[j].setColorRed();
			_tab[j-1].setColorGreen();
			DoDelay();
			std::swap(_tab[j - 1], _tab[j]);
			_tab[j].setColorGreen();
			_tab[j - 1].setColorRed();
			DoDelay();
			_tab[j].setColorWhite();
			_tab[j - 1].setColorWhite();
			j--;
		}
		_tab[i].setColorWhite();
	}
	ControlsOnStop();
}

void GUIMyFrame1::SelectionSort() {
	std::stop_token st = _bgThread.get_stop_token();
	for (int i = 0; i < _tab.size() - 1 && !st.stop_requested(); i++) {
		// find min element in _tab[i ... size - 1]
		SortingElement* min = &_tab[i];
		min->setColorGreen();
		for (int j = i + 1; j < _tab.size() && !st.stop_requested(); j++) {
			_tab[j].setColorRed();
			DoDelay();
			if (_tab[j] < *min) {
				min->setColorWhite();
				min = &_tab[j];
				min->setColorGreen();
			}
			else {
				_tab[j].setColorWhite();
			}
		}
		//
		_tab[i].setColorRed();
		DoDelay();
		// swap min element with current element
		std::swap(_tab[i], *min);
		DoDelay();
		_tab[i].setColorWhite();
		min->setColorWhite();
		DoDelay();
	}
	ControlsOnStop();
}

// additional method to merge two sorted arrays into one 
void GUIMyFrame1::Merge(int p, int q, int r) {
	std::stop_token st = _bgThread.get_stop_token();
	// https://www.programiz.com/dsa/merge-sort
	// https://pl.wikipedia.org/wiki/Sortowanie_przez_scalanie

	// number of elements in left and right tab, after the partition
	int lNum = q - p + 1;
	int rNum = r - q;

	// vectors of elements
	std::vector<SortingElement> tabLeft(lNum);
	std::vector<SortingElement> tabRight(rNum);

	// temporary table for elements from _tab[p..r] in sorted order
	// so that comparising elements from tabLeft and tabRight can be first visualized and then sorted part gets copied to _tab
	std::vector<SortingElement> temporaryTab(lNum + rNum);

	// copy elements from _tab to tabLeft
	for (int i = 0; i < lNum; i++)
		tabLeft[i] = _tab[p + i];

	// copy elements from _tab to tabRight
	for (int i = 0; i < rNum; i++)
		tabRight[i] = _tab[q + 1 + i];

	// numbers tracking current index in leftTab, rightTab
	int leftIndex = 0;
	int rightIndex = 0;

	// current index in temporaryTab
	int currentIndex = 0;

	// merge left and right tab until one of them is empty
	while (leftIndex < lNum && rightIndex < rNum && !st.stop_requested()) {
		_tab[p + leftIndex].setColorRed();
		_tab[q + 1 + rightIndex].setColorRed();

		if (tabLeft[leftIndex] <= tabRight[rightIndex]) {
			temporaryTab[currentIndex] = tabLeft[leftIndex];
			_tab[p + leftIndex].setColorGreen();
			DoDelay();
			_tab[p + leftIndex].setColorWhite();
			_tab[q + 1 + rightIndex].setColorWhite();
			leftIndex++;
		}
		else {
			temporaryTab[currentIndex] = tabRight[rightIndex];
			_tab[q + 1 + rightIndex].setColorGreen();
			DoDelay();
			_tab[p + leftIndex].setColorWhite();
			_tab[q + 1 + rightIndex].setColorWhite();
			rightIndex++;
		}
		currentIndex++;
	}

	// copy elements remaining only in left table
	while (leftIndex < lNum && !st.stop_requested()) {
		_tab[p + leftIndex].setColorGreen();
		DoDelay();
		temporaryTab[currentIndex] = tabLeft[leftIndex];
		_tab[p + leftIndex].setColorWhite();
		leftIndex++;
		currentIndex++;
	}

	// copy elements remaining only in right table
	while (rightIndex < rNum && !st.stop_requested()) {
		_tab[q + 1 + rightIndex].setColorGreen();
		DoDelay();
		temporaryTab[currentIndex] = tabRight[rightIndex];
		_tab[q + 1 + rightIndex].setColorWhite();
		rightIndex++;
		currentIndex++;
	}

	// copy elements from temporaryTab to _tab and display the process (copied elements are drawn as blue)
	for (int i = 0; i < (lNum + rNum) && !st.stop_requested(); i++) {
		_tab[p + i] = temporaryTab[i];
		_tab[p + i].setColorBlue();
		DoDelay();
		_tab[p + i].setColorWhite();
	}
}

void GUIMyFrame1::MergeSort(int p, int r) { // p, r - beginning, end index
	std::stop_token st = _bgThread.get_stop_token();
	// check if array indexes are right
	if (p >= r || st.stop_requested())
		return;

	int q = (p + r) / 2; // q - middle index

	// sort left part recursively
	MergeSort(p, q);
	// sort right part recursivelly
	MergeSort(q+1, r);
	// merge sorted parts
	Merge(p, q, r);
	if(p == 0 && r == _tab.size()-1)
		ControlsOnStop();
}

int GUIMyFrame1::parentNode(int i) {
	return floor((i-1) / 2);
}

int GUIMyFrame1::leftChildNode(int i) {
	return 2 * i + 1;
}

int GUIMyFrame1::rightChildNode(int i) {
	return 2 * i + 2;
}

void GUIMyFrame1::heapify() {
	std::stop_token st = _bgThread.get_stop_token();

	int start = parentNode(_tab.size() - 1) + 1;

	while (start > 0 && !st.stop_requested()) {
		start--;
		siftDown(start, _tab.size());
	}
	for (auto& elem : _tab) {
		if (st.stop_requested()) return;
		elem.setColorGreen();
		DoDelay();
	}
}

void GUIMyFrame1::siftDown(int root, int end) {
	std::stop_token st = _bgThread.get_stop_token();

	while (leftChildNode(root) < end && !st.stop_requested()) {
		int child = leftChildNode(root);

		if (child + 1 < end && _tab[child] < _tab[child + 1])
			child++;

		_tab[root].setColorBlue();
		_tab[child].setColorRed();
		if (_tab[root] < _tab[child]) {
			DoDelay();
			std::swap(_tab[root], _tab[child]);
			_tab[root].setColorRed();
			_tab[child].setColorBlue();
			DoDelay();
			if (end == _tab.size()) {
				_tab[root].setColorWhite();
				_tab[child].setColorWhite();
			}
			else {
				_tab[root].setColorGreen();
				_tab[child].setColorGreen();
			}
			root = child;
		}
		else {
			if (end == _tab.size()) {
				_tab[root].setColorWhite();
				_tab[child].setColorWhite();
			}
			else {
				_tab[root].setColorGreen();
				_tab[child].setColorGreen();
			}
			return;
		}
	}
}

void GUIMyFrame1::HeapSort() {
	std::stop_token st = _bgThread.get_stop_token();

	heapify();

	int end = _tab.size();

	while (end > 1 && !st.stop_requested()) {
		end--;
		_tab[end].setColorBlue();
		_tab[0].setColorRed();
		DoDelay();
		std::swap(_tab[end], _tab[0]);
		_tab[end].setColorRed();
		_tab[0].setColorBlue();
		DoDelay();
		_tab[end].setColorWhite();
		_tab[0].setColorWhite();
		siftDown(0, end);
	}
	ControlsOnStop();
}

void GUIMyFrame1::StdSort() {
	std::stop_token st = _bgThread.get_stop_token();
	try {
		std::sort(_tab.begin(), _tab.end(), [this, st](const SortingElement& o1, const SortingElement& o2) {
			if (st.stop_requested())
				throw std::exception();
			else {
				o1.setColorGreen();
				o2.setColorBlue();
				DoDelay();
				o1.setColorWhite();
				o2.setColorWhite();
				return o1 < o2;
			}
			});
		ControlsOnStop();
	}
	catch (std::exception e) {}
}

void GUIMyFrame1::QuickSortLomuto(int lo, int hi) {
	std::stop_token st = _bgThread.get_stop_token();

	if (lo >= hi || lo < 0 || st.stop_requested())
		return;

	// Partition array and get the pivot index
	int p = partitionLomuto(lo, hi);

	// Sort the two partitions
	if (!st.stop_requested()) {
		QuickSortLomuto(lo, p - 1); // Left side of pivot
		QuickSortLomuto(p + 1, hi); // Right side of pivot

		if (lo == 0 && hi == _tab.size() - 1)
			ControlsOnStop();
	}
}

int GUIMyFrame1::partitionLomuto(int lo, int hi) {
	// https://en.wikipedia.org/wiki/Quicksort

	std::stop_token st = _bgThread.get_stop_token();

	SortingElement& pivot = _tab[hi]; // Choose the last element as the pivot

	pivot.setColorRed();

	// Temporary pivot index
	int i = lo - 1; 

	for (int j = lo; j <= hi - 1 && !st.stop_requested(); j++) {
		_tab[j].setColorGreen();
		if (i > lo - 1) _tab[i].setColorBlue();
		DoDelay();

		// If the current element is less than or equal to the pivot
		if (_tab[j] <= pivot && !st.stop_requested()) {
			if (i > lo - 1) _tab[i].setColorWhite();
			// Move the temporary pivot index forward
			i++;
			_tab[i].setColorBlue();
			DoDelay();
			_tab[i].setColorOrange();
			_tab[j].setColorOrange();
			DoDelay();
			// Swap the current element with the element at the temporary pivot index
			std::swap(_tab[i], _tab[j]);
			DoDelay();
			_tab[i].setColorBlue();
			_tab[j].setColorGreen();
			DoDelay();
		}
		_tab[j].setColorWhite();
	}

	// Move the pivot element to the correct pivot position (between the smaller and larger elements)
	i++;
	if (!st.stop_requested()) {
		DoDelay();
		_tab[i].setColorOrange();
		pivot.setColorOrange();
		DoDelay();
		std::swap(_tab[i], pivot);
		DoDelay();
	}
	_tab[i].setColorWhite();
	pivot.setColorWhite();
	_tab[lo].setColorWhite();

	return i; // the pivot index
}

void GUIMyFrame1::QuickSortHoare(int lo, int hi) {
	std::stop_token st = _bgThread.get_stop_token();

	if (lo >= 0 && hi >= 0 && lo < hi && !st.stop_requested()) {
		int p = partitionHoare(lo, hi);
		QuickSortHoare(lo, p); // Note: the pivot is now included
		QuickSortHoare(p + 1, hi);

		if (lo == 0 && hi == _tab.size() - 1)
			ControlsOnStop();
	}
}

int GUIMyFrame1::partitionHoare(int lo, int hi) {
	// https://en.wikipedia.org/wiki/Quicksort

	std::stop_token st = _bgThread.get_stop_token();

	// Pivot value
	SortingElement& pivot = _tab[lo]; // Choose the first element as the pivot

	pivot.setColorRed();

	// Left index
	int i = lo - 1;

	// Right index
	int j = hi + 1;

	while (!st.stop_requested()) {
		// Move the left index to the right at least once and while the element at
		// the left index is less than the pivot
		do {
			if(i>lo-1) _tab[i].setColorWhite();
			i++;
			_tab[i].setColorGreen();
			pivot.setColorRed();
			DoDelay();
			_tab[i].setColorWhite();
			pivot.setColorRed();
		} while (_tab[i] < pivot && !st.stop_requested());
		_tab[i].setColorGreen();

		// Move the right index to the left at least once and while the element at
		// the right index is greater than the pivot
		do {
			if(j<hi+1) _tab[j].setColorWhite();
			j--;
			_tab[j].setColorBlue();
			pivot.setColorRed();
			DoDelay();
			_tab[j].setColorWhite();
			pivot.setColorRed();
		} while (_tab[j] > pivot && !st.stop_requested());

		_tab[j].setColorBlue();

		// If the indices crossed, return
		if (i >= j || st.stop_requested()) {
			pivot.setColorWhite();
			_tab[i].setColorWhite();
			_tab[j].setColorWhite();
			return j;
		}

		// Swap the elements at the left and right indices
		_tab[i].setColorGreen();
		_tab[j].setColorBlue();
		DoDelay();
		std::swap(_tab[i], _tab[j]);
		DoDelay();
	}
}

void GUIMyFrame1::ShellSort() {
	std::stop_token st = _bgThread.get_stop_token();
	// https://en.wikipedia.org/wiki/Shellsort

	// gaps sequence
	int gaps[] = { 701, 301, 132, 57, 23, 10, 4, 1 };

	for (int gap : gaps) {
		if (st.stop_requested()) break;
		// insertion sort for each gap from gaps tab
		for (int i = gap; i < _tab.size() && !st.stop_requested(); i++) {
			int j = i;
			_tab[i].setColorBlue();
			while (j >= gap && _tab[j - gap] > _tab[j] && !st.stop_requested()) {
				_tab[i].setColorBlue();
				_tab[j].setColorRed();
				_tab[j - gap].setColorGreen();
				DoDelay();
				std::swap(_tab[j - gap], _tab[j]);
				_tab[j].setColorGreen();
				_tab[j - gap].setColorRed();
				DoDelay();
				_tab[j].setColorWhite();
				_tab[j - gap].setColorWhite();
				j -= gap;
			}
			_tab[i].setColorWhite();
		}
	}
	ControlsOnStop();
}

void GUIMyFrame1::CocktailShakerSort() {
	std::stop_token st = _bgThread.get_stop_token();
	int bottom = 0;
	int top = _tab.size() - 1;
	bool swapped = true;
	while (swapped && !st.stop_requested()) {
		swapped = false;
		for (int i = bottom; i < top && !st.stop_requested(); i++) {
			_tab[i].setColorRed();
			_tab[i + 1].setColorGreen();
			DoDelay();
			if (_tab[i] > _tab[i + 1]) {
				std::swap(_tab[i], _tab[i + 1]);
				swapped = true;
				DoDelay();
			}
			_tab[i].setColorWhite();
			_tab[i + 1].setColorWhite();
		}
		top--;
		for (int i = top; i > bottom && !st.stop_requested(); i--) {
			_tab[i].setColorRed();
			_tab[i - 1].setColorGreen();
			DoDelay();
			if (_tab[i] < _tab[i - 1]) {
				std::swap(_tab[i], _tab[i - 1]);
				swapped = true;
				DoDelay();
			}
			_tab[i].setColorWhite();
			_tab[i - 1].setColorWhite();
		}
		bottom++;
	}
	ControlsOnStop();
}

void GUIMyFrame1::OddEvenSort() {
	// https://en.wikipedia.org/wiki/Odd%E2%80%93even_sort

	std::stop_token st = _bgThread.get_stop_token();

	bool sorted = false;
	while (!sorted && !st.stop_requested()) {
		sorted = true;
		for (int i = 1; i < _tab.size() - 1 && !st.stop_requested(); i += 2) {
			_tab[i].setColorRed();
			_tab[i + 1].setColorGreen();
			DoDelay();

			if (_tab[i] > _tab[i + 1]) {
				std::swap(_tab[i], _tab[i+1]);
				sorted = false;
				DoDelay();
			}

			_tab[i].setColorWhite();
			_tab[i + 1].setColorWhite();
		}
		for (int i = 0; i < _tab.size() - 1 && !st.stop_requested(); i += 2) {
			_tab[i].setColorBlue();
			_tab[i + 1].setColorYellow();
			DoDelay();

			if (_tab[i] > _tab[i + 1]) {
				std::swap(_tab[i], _tab[i + 1]);
				sorted = false;
				DoDelay();
			}

			_tab[i].setColorWhite();
			_tab[i + 1].setColorWhite();
		}
	}
	ControlsOnStop();
}

void GUIMyFrame1::m_sliderDelayOnScroll(wxScrollEvent& event) {
	// calculations from:
	// https://stackoverflow.com/questions/846221/logarithmic-slider

	double minp = 0;
	double maxp = 50;

	double minv = std::log(100);
	double maxv = std::log(1'000'000);

	double scale = (maxv - minv) / (maxp - minp);

	_delayTimeInUs = std::exp(minv + scale * (static_cast<double>(m_sliderDelay->GetValue()) - minp));
}

void GUIMyFrame1::m_TimerOnTimer(wxTimerEvent& event) {
	m_ComparisonsNum->SetLabel(std::to_string(SortingElement::comparisonNum));
	drawPanel->Refresh(false);

	// https://stackoverflow.com/questions/29200635/convert-float-to-string-with-precision-number-of-decimal-digits-specified
	double temp = _delayTimeInUs / 1000; // us => ms (?)
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << temp;
	std::string s = stream.str();

	m_staticTextDelay->SetLabel(s);
}

void GUIMyFrame1::DoDelay() {
	//wxMicroSleep(static_cast<int>(_delayTimeInUs));
	std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(_delayTimeInUs)));
}