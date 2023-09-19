#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent), _maxElemValue{ m_slider_Num_of_Elem->GetValue()}, _delayTimeInUs{20}, _comparisonsNumber{0}, _tab{&_delayTimeInUs}
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
		wxBrush tempBrush(_tab.GetColor(i));
		wxPen tempPen(_tab.GetColor(i), 0);

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

	DisableButtons();
	
	std::thread worker;

	if (m_choice_SortType->GetSelection() == BUBBLE_SORT) {
		// sorting to be done on different thread to keep GUI responsive
		worker = std::thread(&GUIMyFrame1::BubbleSort, this);
	}
	else if (m_choice_SortType->GetSelection() == INSERTION_SORT) {
		// sorting to be done on different thread to keep GUI responsive
		worker = std::thread(&GUIMyFrame1::InsertionSort, this);
	}
	else if (m_choice_SortType->GetSelection() == MERGE_SORT) {

	}
	else if (m_choice_SortType->GetSelection() == HEAP_SORT) {

	}
	else if (m_choice_SortType->GetSelection() == STD_SORT) {
		worker = std::thread(&GUIMyFrame1::StdSort, this);
	}
	// detaching thread
	if(worker.joinable())
		worker.detach();
}

void GUIMyFrame1::m_button_ShuffleOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_ShuffleOnButtonClick
	UpdateTab();
	
}

void GUIMyFrame1::m_button_PauseOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_PauseOnButtonClick
}

void GUIMyFrame1::m_button_StopOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_StopOnButtonClick
}

void GUIMyFrame1::m_button_ResetOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_ResetOnButtonClick
}

void GUIMyFrame1::UpdateTab()
{
	_tab.clear();

	int TabSize = m_slider_Num_of_Elem->GetValue();
	
	// https://en.cppreference.com/w/cpp/algorithm/random_shuffle
	std::random_device rd;
	std::mt19937 g(rd());
	//
	std::uniform_int_distribution<std::mt19937::result_type> distrTabSize(0, TabSize - 1); // returns number between 0 and (TabSize - 1)
	std::uniform_int_distribution<std::mt19937::result_type> distrCloseElement(0, 2); // return number between 0 and 3

	if (m_shuffleType->GetSelection() == RANDOM_SHUFFLE) {
		for (int i = 0; i < TabSize; i++)
				_tab.push_back(SortingElement(i + 1));

		std::shuffle(_tab.begin(), _tab.end(), g);
	}
	else if (m_shuffleType->GetSelection() == NEARLY_SORTED) {
		for (int i = 0; i < TabSize; i++)
			_tab.push_back(SortingElement(i + 1));

		for (int i = 0; i < TabSize; i++) {
			int indx1 = distrTabSize(g); // random index of first element to swap
			int indx2 = indx1 + distrCloseElement(g); // random index of second element to swap, not farther than value returned by distrCloseElement

			while (indx2 < 0 || indx2 >= TabSize) indx2 = indx1 + distrCloseElement(g); // generate new index if previous is invalid

			std::swap(_tab[indx1], _tab[indx2]); // swap two elements (they are close to each other)
		}
	}
	else if (m_shuffleType->GetSelection() == MANY_DUPLICATES) {
		// array FewUnique containing 6 numbers used later as values for _tab 
		int FewUnique[] = {
			// 5 random numbers in range from 1 to TabSize
			static_cast<int>(distrTabSize(g) + 1),
			static_cast<int>(distrTabSize(g) + 1),
			static_cast<int>(distrTabSize(g) + 1),
			static_cast<int>(distrTabSize(g) + 1),
			static_cast<int>(distrTabSize(g) + 1),
			// 1 maximal value so that elements are always displayed nicely (correct scale)
			TabSize
		};
		std::uniform_int_distribution<std::mt19937::result_type> distrFewUnique(0, 5); // random index from 0 to 5 to get number from array FewUnique
		for (int i = 0; i < TabSize; i++)
			_tab.push_back(SortingElement(FewUnique[distrFewUnique(g)]));
	}
	else if (m_shuffleType->GetSelection() == DESCENDING_ORDER) {
		for (int i = TabSize; i > 0; i--)
			_tab.push_back(SortingElement(i));
	}
	else if (m_shuffleType->GetSelection() == ALREADY_SORTED) {
		for (int i = 0; i < TabSize; i++)
			_tab.push_back(SortingElement(i + 1));
	}
}

int GUIMyFrame1::GetShift(int w) {
	int AllElemWidth = _tab.size() * int(w / _tab.size());
	return (w - AllElemWidth) / 2;
}

void GUIMyFrame1::BubbleSort() {

	for (int i = 0; i < _tab.size() - 1; i++)
		for (int j = 0; j < _tab.size() - i - 1; j++) {

			_tab[j].SetColorRed();
			_tab[j + 1].SetColorGreen();

			if (_tab.GetValue(j+1) < _tab.GetValue(j))
				_tab.swap(j + 1, j);

			++_comparisonsNumber;

			_tab[j].SetColorWhite();
			_tab[j + 1].SetColorWhite();
		}
	EnableButtons();
}

void GUIMyFrame1::InsertionSort() {
	int i, key, j;
	for (i = 1; i < _tab.size(); i++) {
		key = _tab[i]._value;
		j = i - 1;

			_tab[i]._color = wxColor(0, 255, 255);

		while (j >= 0 && _tab[j]._value > key) {
				_tab[j]._color = wxColor(255, 0, 0);
			_tab[j + 1]._value = _tab[j]._value;
			std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(_delayTimeInUs)));
				_tab[j]._color = wxColor(255, 255, 255);
			j = j - 1;
			++_comparisonsNumber;
		}
		++_comparisonsNumber;
		_tab[j + 1]._value = key;

			_tab[i]._color = wxColor(255, 255, 255);
	}
	EnableButtons();
}

void GUIMyFrame1::StdSort() {
	std::sort(_tab.begin(), _tab.end(), [this](const SortingElement& o1, const SortingElement& o2) {
		o1._color = wxColor(255, 0, 0);
		o2._color = wxColor(0, 255, 0);
		
		++_comparisonsNumber;

		std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(_delayTimeInUs)));

			o1._color = wxColor(255, 255, 255);
			o2._color = wxColor(255, 255, 255);

		return o1 < o2;
	});
	EnableButtons();
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