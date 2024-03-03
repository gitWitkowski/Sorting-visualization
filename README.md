
# Sorting algorithms visualization

Simple project that allows user to visualize different sorting algorithms with given parameters such as number of elements and delay.

-----

### Goal of the project
This project was built in my free time to practise programming skills and refresh some of my knowledge about sorting algorithms, as well as to continue writing programs in C++ myself, after finishing a C++ course at university. Additionally, I learned the basics of multithreading in C++ and got acquainted with [`std::jthread`](https://en.cppreference.com/w/cpp/thread/jthread) which is part of C++20.

-----

### Technologies used
- C++
- [wxWidgets](https://www.wxwidgets.org/)
- [wxFormBuilder](https://sourceforge.net/projects/wxformbuilder/)
- Microsoft Visual Studio

-----

### Features
- 11 sorting algorithms to choose from
    - [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) 
    - [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
    - [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
    - [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
    - [Heapsort](https://en.wikipedia.org/wiki/Heapsort)
    - [std::sort](https://en.cppreference.com/w/cpp/algorithm/sort)
    - [Quicksort Hoare partition scheme](https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme)
    - [Quicksort Lomuto partition scheme](https://en.wikipedia.org/wiki/Quicksort#Lomuto_partition_scheme)
    - [Shellsort](https://en.wikipedia.org/wiki/Shellsort)
    - [Cocktail shaker sort](https://en.wikipedia.org/wiki/Cocktail_shaker_sort)
    - [Odd–even sort](https://en.wikipedia.org/wiki/Odd%E2%80%93even_sort)
- Adjustment of the number of elements (25-500)
- 5 different elements shuffle types
    - Random shuffle
    - Nearly sorted
    - Many duplicates
    - Descending order
    - Already sorted
- Adjustment of the delay between sorting operations (0.1 - 1000 ms)

-----

### Application demo

GUI of the application:

![alt text](https://github.com/gitWitkowski/Sorting-visualization/blob/main/Demo/start_gui.jpg)

Merge sort performed on the randomly shuffled array:

https://github.com/gitWitkowski/Sorting-visualization/assets/73957636/104cb693-88e1-4610-b21f-7c9c14daab5a

Shellsort performed on the array with elements in descending order:

https://github.com/gitWitkowski/Sorting-visualization/assets/73957636/ba2b79bf-a86a-417d-94c9-9395f1b62c93

-----

### Usage

Select the sorting type from the drop down list and set the number of elements using slider. Modify an array with the chosen shuffle type and start the animation. You can adjust the sorting speed while animation is taking place, as well as stop it before it finishes.

-----

### How to run the project

1. Clone git repository:
```
git clone https://github.com/gitWitkowski/Sorting-visualization.git
```
2. [Download](https://www.wxwidgets.org/downloads/) and [build](https://wiki.wxwidgets.org/Install) wxWidgets
3. Copy wxWidgets directory (named `wxWidgets`) into project directory
4. Open project file (`.sln`) using Visual Studio
5. Compile and run the project