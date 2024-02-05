#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent), _maxElemValue{ m_slider_Num_of_Elem->GetValue()}, _delayTimeInUs{20}, _comparisonsNumber{0}
{
	m_ComparisonsNum->SetLabel(std::to_string(_comparisonsNumber));
	UpdateTab();
	// 60 fsp (1000 ms / 60 frames)
	m_Timer.Start(1000 / 60);
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

	case IN_PLACE_MERGE_SORT: // 4
		_bgThread = std::jthread(&GUIMyFrame1::InPlaceMergeSort, this);
		break;

	case HEAP_SORT: // 5
		_bgThread = std::jthread(&GUIMyFrame1::HeapSort, this);
		break;

	case STD_SORT: // 6
		_bgThread = std::jthread(&GUIMyFrame1::StdSort, this);
		break;

	case QUICK_SORT: // 7
		_bgThread = std::jthread(&GUIMyFrame1::QuickSort, this);
		break;

	case TIM_SORT: // 8
		_bgThread = std::jthread(&GUIMyFrame1::TimSort, this);
		break;

	case SHELL_SORT: // 9
		_bgThread = std::jthread(&GUIMyFrame1::ShellSort, this);
		break;

	case COCKTAIL_SHAKER_SORT: // 10
		_bgThread = std::jthread(&GUIMyFrame1::CocktailShakerSort, this);
		break;

	case COMB_SORT: // 11
		_bgThread = std::jthread(&GUIMyFrame1::CombSort, this);
		break;

	case GNOME_SORT: // 12
		_bgThread = std::jthread(&GUIMyFrame1::GnomeSort, this);
		break;

	case ODD_EVEN_SORT: // 13
		_bgThread = std::jthread(&GUIMyFrame1::OddEvenSort, this);
		break;

	case STRAND_SORT: // 14
		_bgThread = std::jthread(&GUIMyFrame1::StrandSort, this);
		break;

	default:
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
	std::stop_callback sc(st, [this] { UpdateTab(); });

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

void GUIMyFrame1::BubbleSort() {
	int size = _tab.size();
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
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
}

void GUIMyFrame1::InsertionSort() {
	// https://en.wikipedia.org/wiki/Insertion_sort
	
	for (int i = 0; i < _tab.size(); i++) {
		int j = i;
		_tab[i].setColorBlue();
		while (j > 0 && _tab[j-1] > _tab[j]) {
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
}

void GUIMyFrame1::SelectionSort() {
	for (int i = 0; i < _tab.size() - 1; i++) {
		// find min element in _tab[i ... size - 1]
			SortingElement* min = &_tab[i];
			min->setColorGreen();
			for (int j = i + 1; j < _tab.size(); j++) {
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
}

// additional method to merge two sorted arrays into one 
void GUIMyFrame1::Merge(int p, int q, int r) {
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
	while (leftIndex < lNum && rightIndex < rNum) {
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
	while (leftIndex < lNum) {
		_tab[p + leftIndex].setColorGreen();
		DoDelay();
		temporaryTab[currentIndex] = tabLeft[leftIndex];
		_tab[p + leftIndex].setColorWhite();
		leftIndex++;
		currentIndex++;
	}

	// copy elements remaining only in right table
	while (rightIndex < rNum) {
		_tab[q + 1 + rightIndex].setColorGreen();
		DoDelay();
		temporaryTab[currentIndex] = tabRight[rightIndex];
		_tab[q + 1 + rightIndex].setColorWhite();
		rightIndex++;
		currentIndex++;
	}

	// copy elements from temporaryTab to _tab and display the process (copied elements are drawn as blue)
	for (int i = 0; i < (lNum + rNum); i++) {
		_tab[p + i] = temporaryTab[i];
		_tab[p + i].setColorBlue();
		DoDelay();
		_tab[p + i].setColorWhite();
	}
}

void GUIMyFrame1::MergeSort(int p, int r) { // p, r - beginning, end index
	// check if array indexes are right
	if (p >= r)
		return;

	int q = (p + r) / 2; // q - middle index
	
	// sort left part recursively
	MergeSort(p, q);
	// sort right part recursivelly
	MergeSort(q+1, r);
	// merge sorted parts
	Merge(p, q, r);
}

void GUIMyFrame1::InPlaceMergeSort() {

}

void GUIMyFrame1::HeapSort() {

}

void GUIMyFrame1::StdSort() {
	std::sort(_tab.begin(), _tab.end(), [this](const SortingElement& o1, const SortingElement& o2) {
		o1.setColorGreen();
		o2.setColorBlue();
		DoDelay();
		o1.setColorWhite();
		o2.setColorWhite();
		return o1 < o2;
	});
}

void GUIMyFrame1::QuickSort() {

}

void GUIMyFrame1::TimSort() {

}

void GUIMyFrame1::ShellSort() {
	// https://en.wikipedia.org/wiki/Shellsort

	// gaps sequence
	int gaps[] = { 701, 301, 132, 57, 23, 10, 4, 1 };

	for (int gap : gaps) {
		// insertion sort for each gap from gaps tab
		for (int i = gap; i < _tab.size(); i++) {
			int j = i;
			_tab[i].setColorBlue();
			while (j>=gap && _tab[j - gap] > _tab[j]) {
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
				j-=gap;
			}
			_tab[i].setColorWhite();
		}
	}
}

void GUIMyFrame1::CocktailShakerSort() {
	int bottom = 0;
	int top = _tab.size() - 1;
	bool swapped = true;
	while (swapped) {
		swapped = false;
		for (int i = bottom; i < top; i++) {
			_tab[i].setColorRed();
			_tab[i+1].setColorGreen();
			DoDelay();
			if (_tab[i] > _tab[i + 1]) {
				std::swap(_tab[i], _tab[i + 1]);
				swapped = true;
				DoDelay();
			}
			_tab[i].setColorWhite();
			_tab[i+1].setColorWhite();
		}
		top--;
		for (int i = top; i > bottom; i--) {
			_tab[i].setColorRed();
			_tab[i-1].setColorGreen();
			DoDelay();
			if (_tab[i] < _tab[i - 1]) {
				std::swap(_tab[i], _tab[i - 1]);
				swapped = true;
				DoDelay();
			}
			_tab[i].setColorWhite();
			_tab[i-1].setColorWhite();
		}
		bottom++;
	}

}

void GUIMyFrame1::CombSort() {

}

void GUIMyFrame1::GnomeSort() {

}

void GUIMyFrame1::OddEvenSort() {

}

void GUIMyFrame1::StrandSort() {

}


void GUIMyFrame1::m_sliderDelayOnScroll(wxScrollEvent& event) {
	// calculations from:
	// https://stackoverflow.com/questions/846221/logarithmic-slider
	
	double minp = 0;
	double maxp = 50;

	double minv = std::log(1);
	double maxv = std::log(10000000);

	double scale = (maxv - minv) / (maxp - minp);

	_delayTimeInUs = std::exp(minv + scale * (static_cast<double>(m_sliderDelay->GetValue()) - minp))/10;
}

void GUIMyFrame1::m_TimerOnTimer(wxTimerEvent& event) {
	m_ComparisonsNum->SetLabel(std::to_string(_comparisonsNumber));
	drawPanel->Refresh(false);

	// https://stackoverflow.com/questions/29200635/convert-float-to-string-with-precision-number-of-decimal-digits-specified
	double temp = _delayTimeInUs / 1000; // us => ms (?)
	std::stringstream stream;
	stream << std::fixed << std::setprecision(4) << temp;
	std::string s = stream.str();

	m_staticTextDelay->SetLabel(s);
}

void GUIMyFrame1::DisableButtons() {
	// reset comparision number
	_comparisonsNumber = 0;

	m_choice_SortType->Disable();
	m_slider_Num_of_Elem->Disable();
	m_shuffleType->Disable();
	m_button_Shuffle->Disable();
	m_button_Sort->Disable();
}

void GUIMyFrame1::EnableButtons() {
	m_choice_SortType->Enable();
	m_slider_Num_of_Elem->Enable();
	m_shuffleType->Enable();
	m_button_Shuffle->Enable();
	m_button_Sort->Enable();
}

void GUIMyFrame1::DoDelay() {
	//wxMicroSleep(static_cast<int>(_delayTimeInUs));
	std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(_delayTimeInUs)));
}