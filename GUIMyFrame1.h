#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <algorithm>
#include "SortingElement.h"

//	sleep
#include <chrono>
#include <thread>
//
#include "main.h"

wxDECLARE_APP(MyApp);


/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void drawPanelOnPaint( wxPaintEvent& event );
		void drawPanelOnSize( wxSizeEvent& event );
		void m_choice_SortTypeOnChoice( wxCommandEvent& event );
		void m_slider_Num_of_ElemOnScroll( wxScrollEvent& event );
		void m_button_SortOnButtonClick( wxCommandEvent& event );
		void m_button_ShuffleOnButtonClick( wxCommandEvent& event );
		void m_button_PauseOnButtonClick( wxCommandEvent& event );
		void m_button_StopOnButtonClick( wxCommandEvent& event );
		void m_button_ResetOnButtonClick( wxCommandEvent& event );
		void m_spinDelayOnSpinCtrlDouble( wxSpinDoubleEvent& event );
		void m_TimerOnTimer( wxTimerEvent& event );
	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
	//// end generated class members
		void UpdateTabSize();
		int GetShift(int); // return number of pixels from left side of the DrawPanel
		void BubbleSort();
		void InsertionSort();
		void StdSort();

		std::vector<SortingElement> _tab;
		int _maxElemValue;
		double _delayTimeInMs;
		int _comparisonsNumber;

		enum {
			BUBBLE_SORT = 0,
			INSERTION_SORT = 1,
			MERGE_SORT = 2,
			HEAP_SORT = 3,
			STD_SORT = 4
		};









};

#endif // __GUIMyFrame1__
