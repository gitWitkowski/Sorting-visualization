#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent), _maxElemValue{ 25 }, _delayTimeInMs{ m_spinDelay->GetValue() }, _comparisonsNumber{0}
{
	m_ComparisonsNum->SetLabel(std::to_string(_comparisonsNumber));
	m_slider_Num_of_Elem->SetValue(20);
	UpdateTabSize();
	// 60 fsp (1000 ms / 60 frames)
	m_Timer.Start(1000 / 60);
}

void GUIMyFrame1::drawPanelOnSize(wxSizeEvent& event)
{
	// TODO: Implement drawPanelOnSize
	std::string text = std::to_string(drawPanel->GetSize().x);
	m_staticText2->SetLabel(text);
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
	UpdateTabSize();
}

void GUIMyFrame1::m_button_SortOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_SortOnButtonClick

	_comparisonsNumber = 0;
	
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
	UpdateTabSize();
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

void GUIMyFrame1::UpdateTabSize()
{
	_tab.clear();
	for (int i = 0; i < m_slider_Num_of_Elem->GetValue(); i++)
		_tab.push_back(getNewRandomElement(_maxElemValue));
}

int GUIMyFrame1::GetShift(int w) {
	int AllElemWidth = _tab.size() * int(w / _tab.size());
	return (w - AllElemWidth) / 2;
}

void GUIMyFrame1::BubbleSort() {

	for (int i = 0; i < _tab.size() - 1; i++)
		for (int j = 0; j < _tab.size() - i - 1; j++) {

			wxGetApp().CallAfter([this, j] {
				_tab[j]._color = wxColor(255, 0, 0);
				_tab[j + 1]._color = wxColor(0, 255, 0);
			});

			if (_tab[j + 1] < _tab[j])
				std::swap(_tab[j + 1], _tab[j]);

			++_comparisonsNumber;

			std::this_thread::sleep_for(std::chrono::nanoseconds(static_cast<int>(_delayTimeInMs * 1000)));

			wxGetApp().CallAfter([this, j] {
				_tab[j]._color = wxColor(255, 255, 255);
				_tab[j + 1]._color = wxColor(255, 255, 255);
			});
		}
}

void GUIMyFrame1::InsertionSort() {
	int i, key, j;
	for (i = 1; i < _tab.size(); i++) {
		key = _tab[i]._value;
		j = i - 1;

		wxGetApp().CallAfter([this, i] {
			_tab[i]._color = wxColor(0, 255, 255);
		});

		while (j >= 0 && _tab[j]._value > key) {
			wxGetApp().CallAfter([this, j] {
				_tab[j]._color = wxColor(255, 0, 0);
			});
			_tab[j + 1] = _tab[j];
			std::this_thread::sleep_for(std::chrono::nanoseconds(static_cast<int>(_delayTimeInMs * 1000)));
			wxGetApp().CallAfter([this, j] {
				_tab[j]._color = wxColor(255, 255, 255);
			});
			j = j - 1;
			++_comparisonsNumber;
		}
		++_comparisonsNumber;
		_tab[j + 1]._value = key;

		wxGetApp().CallAfter([this, i] {
			_tab[i]._color = wxColor(255, 255, 255);
		});
	}
}

void GUIMyFrame1::StdSort() {
	std::sort(_tab.begin(), _tab.end(), [this](SortingElement& o1, SortingElement& o2) {
		// color changing operation temporary outside main thread?
		o1._color = wxColor(255, 0, 0);
		o2._color = wxColor(0, 255, 0);
		
		++_comparisonsNumber;

		std::this_thread::sleep_for(std::chrono::nanoseconds(static_cast<int>(_delayTimeInMs * 1000)));

		//wxGetApp().CallAfter([o1, o2] {
			o1._color = wxColor(255, 255, 255);
			o2._color = wxColor(255, 255, 255);
		//});

		return o1 < o2;
	});
}

void GUIMyFrame1::m_spinDelayOnSpinCtrlDouble(wxSpinDoubleEvent& event) {
	_delayTimeInMs = m_spinDelay->GetValue();
}

void GUIMyFrame1::m_TimerOnTimer(wxTimerEvent& event) {
	m_ComparisonsNum->SetLabel(std::to_string(_comparisonsNumber));
	drawPanel->Refresh(false);
}
