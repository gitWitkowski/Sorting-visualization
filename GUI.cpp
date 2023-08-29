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
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	staticText_title = new wxStaticText( this, wxID_ANY, wxT("title"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	staticText_title->Wrap( -1 );
	staticText_title->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	staticText_title->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer2->Add( staticText_title, 1, wxALIGN_CENTER|wxALL, 0 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	drawPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	drawPanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer4->Add( drawPanel, 1, wxEXPAND | wxALL, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxString m_choice_SortTypeChoices[] = { wxT("sort 1"), wxT("sort 2"), wxT("sort 3"), wxT("sort 4"), wxT("sort 5") };
	int m_choice_SortTypeNChoices = sizeof( m_choice_SortTypeChoices ) / sizeof( wxString );
	m_choice_SortType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_SortTypeNChoices, m_choice_SortTypeChoices, 0 );
	m_choice_SortType->SetSelection( 0 );
	bSizer5->Add( m_choice_SortType, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Number of elements"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider_Num_of_Elem = new wxSlider( this, wxID_ANY, 10, 25, 600, wxDefaultPosition, wxSize( -1,300 ), wxSL_VALUE_LABEL|wxSL_VERTICAL );
	bSizer5->Add( m_slider_Num_of_Elem, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_Sort = new wxButton( this, wxID_ANY, wxT("Sort"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_Sort, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_Shuffle = new wxButton( this, wxID_ANY, wxT("Shuffle"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_Shuffle, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_Pause = new wxButton( this, wxID_ANY, wxT("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_Pause, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_Stop = new wxButton( this, wxID_ANY, wxT("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_Stop, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_Reset = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_Reset, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer3->Add( bSizer5, 0, wxEXPAND, 5 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	drawPanel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::drawPanelOnUpdateUI ), NULL, this );
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
	m_button_Sort->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_SortOnButtonClick ), NULL, this );
	m_button_Shuffle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_ShuffleOnButtonClick ), NULL, this );
	m_button_Pause->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_PauseOnButtonClick ), NULL, this );
	m_button_Stop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_StopOnButtonClick ), NULL, this );
	m_button_Reset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_ResetOnButtonClick ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	drawPanel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::drawPanelOnUpdateUI ), NULL, this );
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
	m_button_Sort->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_SortOnButtonClick ), NULL, this );
	m_button_Shuffle->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_ShuffleOnButtonClick ), NULL, this );
	m_button_Pause->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_PauseOnButtonClick ), NULL, this );
	m_button_Stop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_StopOnButtonClick ), NULL, this );
	m_button_Reset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_ResetOnButtonClick ), NULL, this );

}
