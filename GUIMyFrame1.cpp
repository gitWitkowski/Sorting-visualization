#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent), _maxElemValue{ 25 }
{
	//m_slider_Num_of_Elem->SetValue(20);
	UpdateTabSize();
	//Draw();
}

void GUIMyFrame1::drawPanelOnUpdateUI(wxUpdateUIEvent& event)
{
	// TODO: Implement drawPanelOnUpdateUI
	Draw();
}

void GUIMyFrame1::m_choice_SortTypeOnChoice(wxCommandEvent& event)
{
	// TODO: Implement m_choice_SortTypeOnChoice
}

void GUIMyFrame1::m_slider_Num_of_ElemOnScroll(wxScrollEvent& event)
{
	// TODO: Implement m_slider_Num_of_ElemOnScroll
	//_tabSize = m_slider_Num_of_Elem->GetValue();
	UpdateTabSize();
	//std::string text = std::to_string(_tab.size());
	//m_staticText2->SetLabel(text);

	// IDEA! Max number of elements depending of screen width (num. of pixels)

}

void GUIMyFrame1::m_button_SortOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_SortOnButtonClick
}

void GUIMyFrame1::m_button_ShuffleOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement m_button_ShuffleOnButtonClick
	_tab.clear();
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


void GUIMyFrame1::Draw()
{
	wxClientDC dc1(drawPanel);
	wxBufferedDC dc(&dc1);

	dc.Clear();

	int w, h;

	drawPanel->GetSize(&w, &h);

	int tempWidth = w / _tab.size();
	int unitHeight = h / _maxElemValue;

	int shift = GetShift(w);


	for (int i = 0; i < _tab.size(); i++) {
		dc.DrawRectangle(
			wxRect(
				shift + i * tempWidth, h - (unitHeight * _tab[i]._value) - 5,
				tempWidth, unitHeight * _tab[i]._value
			));
	}
}

void GUIMyFrame1::UpdateTabSize()
{
	if (_tab.size() < m_slider_Num_of_Elem->GetValue()) {
		int temp = m_slider_Num_of_Elem->GetValue() - _tab.size();
		for (int i = 0; i < temp; i++)
			_tab.push_back(getNewRandomElement(_maxElemValue));
	}
	else if (_tab.size() > m_slider_Num_of_Elem->GetValue()) {
		int temp = _tab.size() - m_slider_Num_of_Elem->GetValue();
		for (int i = 0; i < temp; i++)
			_tab.pop_back();
	}
}

int GUIMyFrame1::GetShift(int w) {
	int AllElemWidth = _tab.size() * int(w / _tab.size());
	return (w - AllElemWidth) / 2;
}