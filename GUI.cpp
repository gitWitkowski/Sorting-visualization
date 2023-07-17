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

	bSizer2->Add( staticText_title, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 0 );


	bSizer1->Add( bSizer2, 0, wxALIGN_CENTER|wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer4->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxString m_choice1Choices[] = { wxT("sort 1"), wxT("sort 2"), wxT("sort 3"), wxT("sort 4"), wxT("sort 5") };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	bSizer5->Add( m_choice1, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Number of elements"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider2 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer5->Add( m_slider2, 0, wxALL, 5 );

	m_button18 = new wxButton( this, wxID_ANY, wxT("Sort"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button18, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Shuffle"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button19, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button20 = new wxButton( this, wxID_ANY, wxT("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button20, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button21, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button22 = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button22, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer3->Add( bSizer5, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MyFrame1::~MyFrame1()
{
}
