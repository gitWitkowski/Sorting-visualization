#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include "main.h"
#include "SortingElement.h"
// graphics
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
// stl
#include <algorithm>
//	sleep
#include <chrono>
#include <thread>
// std::shuffle
#include <random>
// stringstream
#include <sstream>
#include <iomanip>
// unique_ptr
#include <memory>


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
	void m_button_StopOnButtonClick( wxCommandEvent& event );
	void m_sliderDelayOnScroll(wxScrollEvent& event);
	void m_TimerOnTimer( wxTimerEvent& event );
public:
	/** Constructor */
	GUIMyFrame1( wxWindow* parent );
	//// end generated class members
	void UpdateTab();
	int GetShift(int); // return number of pixels from left side of the DrawPanel
	void DoDelay();
	void ControlsOnStart();
	void ControlsOnStop();

	/// sorting methods
	void BubbleSort();
	void InsertionSort();
	void SelectionSort();
	void Merge(int, int, int);
	void MergeSort(int, int);
	void HeapSort();
	void heapify();
	void siftDown(int, int);
	int parentNode(int);
	int leftChildNode(int);
	int rightChildNode(int);
	void StdSort();
	void QuickSortHoare(int, int);
	void QuickSortLomuto(int, int);
	int partitionHoare(int, int);
	int partitionLomuto(int, int);
	void ShellSort();
	void CocktailShakerSort();
	void OddEvenSort();

	std::vector<SortingElement> _tab;
	int _maxElemValue;
	double _delayTimeInUs;
	std::jthread _bgThread;

	enum sortingType {
		BUBBLE_SORT = 0,		// 0
		INSERTION_SORT,			// 1
		SELECTION_SORT,			// 2
		MERGE_SORT,				// 3
		HEAP_SORT,				// 4
		STD_SORT,				// 5
		QUICK_SORT_HOARE,		// 6
		QUICK_SORT_LOMUTO,		// 7
		SHELL_SORT,				// 8
		COCKTAIL_SHAKER_SORT,	// 9
		ODD_EVEN_SORT,			// 10
	};

	enum shiffleType {
		RANDOM_SHUFFLE = 0,
		NEARLY_SORTED,
		MANY_DUPLICATES,
		DESCENDING_ORDER,
		ALREADY_SORTED
	};







};

#endif // __GUIMyFrame1__
