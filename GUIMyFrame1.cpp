#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent), _maxElemValue{ 25 }
{
	//m_slider_Num_of_Elem->SetValue(20);
	UpdateTabSize();
	Draw();
}

void GUIMyFrame1::drawPanelOnSize(wxSizeEvent& event)
{
	// TODO: Implement drawPanelOnSize
	Draw();
	std::string text = std::to_string(drawPanel->GetSize().x);
	m_staticText2->SetLabel(text);
}


void GUIMyFrame1::drawPanelOnUpdateUI(wxUpdateUIEvent& event)
{
	// TODO: Implement drawPanelOnUpdateUI
	
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
	Draw();

}

void GUIMyFrame1::m_button_SortOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_SortOnButtonClick
	std::sort(_tab.begin(), _tab.end(), [&](const SortingElement& o1, const SortingElement& o2) {
		
		o1._color = wxColor(255, 0, 0);
		o2._color = wxColor(0, 255, 0);
		
		Draw();

		o1._color = wxColor(255, 255, 255);
		o2._color = wxColor(255, 255, 255);

		//std::chrono::milliseconds timespan(0); // or whatever

		//std::this_thread::sleep_for(timespan);

		return o1<o2;
	});

	Draw();
}

void GUIMyFrame1::m_button_ShuffleOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_ShuffleOnButtonClick
	UpdateTabSize();
	Draw();
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


void GUIMyFrame1::Draw()
{
	wxClientDC dc1(drawPanel);
	wxBufferedDC dc(&dc1);

	dc.Clear();

	int w, h;

	drawPanel->GetSize(&w, &h);

	int tempWidth = w / _tab.size();
	double unitHeight = (double)h / _maxElemValue;

	int shift = GetShift(w);

	for (int i = 0; i < _tab.size(); i++) {
		wxBrush tempBrush(_tab[i]._color);
		wxPen tempPen(_tab[i]._color, 0);

		dc.SetBrush(tempBrush);
		dc.SetPen(tempPen);

		dc.DrawRectangle(
			wxRect(
				shift + i * tempWidth, h - (unitHeight * _tab[i]._value) - 5,
				tempWidth, unitHeight * _tab[i]._value
			));
	}
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