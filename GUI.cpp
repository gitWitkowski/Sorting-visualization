///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,600 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Comparisons:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer2->Add( m_staticText5, 0, wxALL, 5 );

	m_ComparisonsNum = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxALIGN_RIGHT );
	m_ComparisonsNum->Wrap( -1 );
	bSizer2->Add( m_ComparisonsNum, 0, wxALL, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	drawPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	drawPanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );

	bSizer4->Add( drawPanel, 1, wxEXPAND | wxALL, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxString m_choice_SortTypeChoices[] = { wxT("BUBBLE SORT"), wxT("INSERTION SORT"), wxT("MERGE SORT"), wxT("HEAP SORT"), wxT("STD::SORT") };
	int m_choice_SortTypeNChoices = sizeof( m_choice_SortTypeChoices ) / sizeof( wxString );
	m_choice_SortType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_SortTypeNChoices, m_choice_SortTypeChoices, 0 );
	m_choice_SortType->SetSelection( 0 );
	bSizer5->Add( m_choice_SortType, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Number of elements"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider_Num_of_Elem = new wxSlider( this, wxID_ANY, 25, 25, 600, wxDefaultPosition, wxSize( 130,-1 ), wxSL_VALUE_LABEL );
	bSizer5->Add( m_slider_Num_of_Elem, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString m_shuffleTypeChoices[] = { wxT("RANDOM SHUFFLE"), wxT("NEARLY SORTED"), wxT("MANY DUPLICATES"), wxT("DESCENDING ORDER"), wxT("ALREADY SORTED") };
	int m_shuffleTypeNChoices = sizeof( m_shuffleTypeChoices ) / sizeof( wxString );
	m_shuffleType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_shuffleTypeNChoices, m_shuffleTypeChoices, 0 );
	m_shuffleType->SetSelection( 0 );
	bSizer5->Add( m_shuffleType, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_Shuffle = new wxButton( this, wxID_ANY, wxT("Shuffle"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_Shuffle, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_Sort = new wxButton( this, wxID_ANY, wxT("Sort"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_Sort, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_Pause = new wxButton( this, wxID_ANY, wxT("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_Pause, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_Stop = new wxButton( this, wxID_ANY, wxT("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_Stop, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_Reset = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_Reset, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Delay time (ms)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer5->Add( m_staticText4, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticTextDelay = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 130,-1 ), wxALIGN_CENTER_HORIZONTAL );
	m_staticTextDelay->Wrap( -1 );
	bSizer5->Add( m_staticTextDelay, 0, wxALIGN_CENTER|wxALL, 5 );

	m_sliderDelay = new wxSlider( this, wxID_ANY, 1, 0, 50, wxDefaultPosition, wxSize( 130,-1 ), wxSL_HORIZONTAL );
	bSizer5->Add( m_sliderDelay, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer3->Add( bSizer5, 0, wxEXPAND, 5 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_Timer.SetOwner( this, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	drawPanel->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::drawPanelOnPaint ), NULL, this );
	drawPanel->Connect( wxEVT_SIZE, wxSizeEventHandler( MyFrame1::drawPanelOnSize ), NULL, this );
	m_choice_SortType->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::m_choice_SortTypeOnChoice ), NULL, this );
	m_slider_Num_of_Elem->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_button_Shuffle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_ShuffleOnButtonClick ), NULL, this );
	m_button_Sort->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_SortOnButtonClick ), NULL, this );
	m_button_Pause->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_PauseOnButtonClick ), NULL, this );
	m_button_Stop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_StopOnButtonClick ), NULL, this );
	m_button_Reset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_ResetOnButtonClick ), NULL, this );
	m_sliderDelay->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrame1::m_TimerOnTimer ) );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	drawPanel->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::drawPanelOnPaint ), NULL, this );
	drawPanel->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MyFrame1::drawPanelOnSize ), NULL, this );
	m_choice_SortType->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::m_choice_SortTypeOnChoice ), NULL, this );
	m_slider_Num_of_Elem->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_slider_Num_of_Elem->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_slider_Num_of_ElemOnScroll ), NULL, this );
	m_button_Shuffle->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_ShuffleOnButtonClick ), NULL, this );
	m_button_Sort->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_SortOnButtonClick ), NULL, this );
	m_button_Pause->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_PauseOnButtonClick ), NULL, this );
	m_button_Stop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_StopOnButtonClick ), NULL, this );
	m_button_Reset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_ResetOnButtonClick ), NULL, this );
	m_sliderDelay->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	m_sliderDelay->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_sliderDelayOnScroll ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrame1::m_TimerOnTimer ) );

}
