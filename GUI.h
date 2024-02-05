///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/slider.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/timer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText5;
		wxStaticText* m_ComparisonsNum;
		wxPanel* drawPanel;
		wxChoice* m_choice_SortType;
		wxStaticText* m_staticText2;
		wxSlider* m_slider_Num_of_Elem;
		wxChoice* m_shuffleType;
		wxButton* m_button_Shuffle;
		wxButton* m_button_Sort;
		wxButton* m_button_Stop;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticTextDelay;
		wxSlider* m_sliderDelay;
		wxTimer m_Timer;

		// Virtual event handlers, override them in your derived class
		virtual void drawPanelOnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void drawPanelOnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void m_choice_SortTypeOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider_Num_of_ElemOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_button_ShuffleOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button_SortOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button_StopOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_sliderDelayOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_TimerOnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

