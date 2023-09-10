#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent), _maxElemValue{ 25 }
{
	//m_slider_Num_of_Elem->SetValue(20);
	UpdateTabSize();
	drawPanel->Refresh(false);
}

void GUIMyFrame1::drawPanelOnSize(wxSizeEvent& event)
{
	// TODO: Implement drawPanelOnSize
	drawPanel->Refresh(false);
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
	drawPanel->Refresh(false);

}

void GUIMyFrame1::m_button_SortOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_SortOnButtonClick
	/*std::sort(_tab.begin(), _tab.end(), [&](const SortingElement& o1, const SortingElement& o2) {
		
		o1._color = wxColor(255, 0, 0);
		o2._color = wxColor(0, 255, 0);
		
		drawPanel->Refresh(false);

		o1._color = wxColor(255, 255, 255);
		o2._color = wxColor(255, 255, 255);

		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		return o1<o2;
	});

	drawPanel->Refresh(false);*/

	if (m_choice_SortType->GetSelection() == 0) {
		// sorting to be done on different thread to keep GUI responsive
		std::thread worker(&GUIMyFrame1::BubbleSort, this);
		// detaching thread
		worker.detach();
	}
	else if (m_choice_SortType->GetSelection() == 1) {
		// sorting to be done on different thread to keep GUI responsive
		std::thread worker(&GUIMyFrame1::InsertionSort, this);
		// detaching thread
		worker.detach();
	}
}

void GUIMyFrame1::m_button_ShuffleOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_ShuffleOnButtonClick
	UpdateTabSize();
	drawPanel->Refresh(false);
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

			// GUI updates must take place on main thead
			wxGetApp().CallAfter([this, j] {
				drawPanel->Refresh(false);
				_tab[j]._color = wxColor(255, 0, 0);
				_tab[j + 1]._color = wxColor(0, 255, 0);
			});

			if (_tab[j + 1] < _tab[j])
				std::swap(_tab[j + 1], _tab[j]);

			std::this_thread::sleep_for(std::chrono::nanoseconds(450));

			// GUI updates must take place on main thead
			wxGetApp().CallAfter([this, j] {
				drawPanel->Refresh(false);
				_tab[j]._color = wxColor(255, 255, 255);
				_tab[j + 1]._color = wxColor(255, 255, 255);
			});
		}

	wxGetApp().CallAfter([this] {
		drawPanel->Refresh(false);
	});
}

void GUIMyFrame1::InsertionSort() {
	int i, key, j;
	for (i = 1; i < _tab.size(); i++) {
		key = _tab[i]._value;
		j = i - 1;

		wxGetApp().CallAfter([this, i] {
			_tab[i]._color = wxColor(0, 255, 255);
			drawPanel->Refresh(false);
		});

		// Move elements of arr[0..i-1],
		// that are greater than key,
		// to one position ahead of their
		// current position
		while (j >= 0 && _tab[j]._value > key) {
			wxGetApp().CallAfter([this, j] {
				_tab[j]._color = wxColor(255, 0, 0);
				drawPanel->Refresh(false);
			});
			_tab[j + 1] = _tab[j];
			std::this_thread::sleep_for(std::chrono::nanoseconds(450));
			wxGetApp().CallAfter([this, j] {
				_tab[j]._color = wxColor(255, 255, 255);
				drawPanel->Refresh(false);
			});
			j = j - 1;
		}
		_tab[j + 1]._value = key;

		wxGetApp().CallAfter([this, i] {
			_tab[i]._color = wxColor(255, 255, 255);
			drawPanel->Refresh(false);
		});
	}

	// GUI updates must take place on main thead
	wxGetApp().CallAfter([this, j] {
		drawPanel->Refresh(false);
	});
}

