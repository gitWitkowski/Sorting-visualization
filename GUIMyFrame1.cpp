#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent ), _tabSize(m_slider_Num_of_Elem->GetValue()), _maxElemValue{25}
{
	UpdateTabSize();
	Draw();
}

void GUIMyFrame1::drawPanelOnUpdateUI( wxUpdateUIEvent& event )
{
// TODO: Implement drawPanelOnUpdateUI
	Draw();
}

void GUIMyFrame1::m_choice_SortTypeOnChoice( wxCommandEvent& event )
{
// TODO: Implement m_choice_SortTypeOnChoice
}

void GUIMyFrame1::m_slider_Num_of_ElemOnScroll( wxScrollEvent& event )
{
// TODO: Implement m_slider_Num_of_ElemOnScroll
_tabSize = m_slider_Num_of_Elem->GetValue();
UpdateTabSize();
std::string text = std::to_string(_tab.size());
m_staticText2->SetLabel(text);

}

void GUIMyFrame1::m_button_SortOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_button_SortOnButtonClick
}

void GUIMyFrame1::m_button_ShuffleOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_button_ShuffleOnButtonClick
}

void GUIMyFrame1::m_button_PauseOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_button_PauseOnButtonClick
}

void GUIMyFrame1::m_button_StopOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_button_StopOnButtonClick
}

void GUIMyFrame1::m_button_ResetOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_button_ResetOnButtonClick
}

void GUIMyFrame1::Draw() 
{
	wxClientDC dc1(drawPanel);
	wxBufferedDC dc(&dc1);

	dc.Clear();

	//////////////////////////////////////////////////////////////////
	//				dokonczyc rysowanie elementow
	for (int i = 0; i < _tabSize; i++) {
		dc.DrawRectangle(wxRect(i*20, i*20, 50, 100));
	}
}

void GUIMyFrame1::UpdateTabSize()
{
	if (_tab.size() < _tabSize) {
		for (int i = 0; i < _tabSize - _tab.size(); i++)
			_tab.push_back(getNewRandomElement(_maxElemValue));
	}
	else if (_tab.size() > _tabSize) {
		for (int i = 0; i < _tab.size() - _tabSize; i++)
			_tab.pop_back();
	}	
}