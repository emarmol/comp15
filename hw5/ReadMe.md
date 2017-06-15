# ReadMe for COMP 15 HW5
## Sorting Assignment 

Purpose:
The purpose of the three programs is to sort lists of numbers (both small
and large) in increasing order. The programs are each implemented differently
using a unique sorting algorithm, cauing each sort to have individual space
and time complexities.


Files:
SelectionSort.h - the header file for the selection sort algorithm defining
		the selcetion sort class, and the struct containing a pointer
		to the array.
SelectionSort.cpp - File that provides the implementation of the defined
		functions in the header file. Reads in data, sorts by selection
		sort, and prints
sort2.h -	header file for the insertion sort algorithm defining the 
		insertion sort class, and struct containing a pointer to the
		array.
sort2.cpp -	File providing the implementation of the defined functions in
		the header file. Reads in data, sorts by insertion, and prints
sort3.h -	Header file for the QuickSort class, defining the functions
		and a struct with a pointer to the array.
sort3.cpp -	File providing the implementation of the defined functions in
		the header file. Reads in data, sorts using quicksort, and
		prints the array.

Compiling:
Use included Makefile to compile.

Data Structure:
	Selection Sort: the selection sort uses a dynamic array, which expands
			as needed as the numbers are read in. Selection sort is
			done in place, thus only one dynamic array is needed.
			(not counting the arrays created & destroyed when
			expanding).

	Insertion Sort: this algorithm also uses a dynamic array similar to
			selection sort expanding as needed. Insertion sort is
			also done in place.

	Quick Sort:	this algorithm like, the two sorts above, uses a 
			dynamic array. It's implemented in place, thus only
			one dynamic array is needed.

Algorithm:
	Selection Sort: implemented in-place. Program finds the minimum value
			in the array, and puts it in the furthest left un-
			sorted location. This algorithm uses nested for loops
			to look for all the elemented, making it O(n^2)
			behavior.

	Insertion Sort: also implemented in-place (space complexity: O(n))
			Searches the list (array) starting at the second
			element. Program also uses nested loops to shuffle the
			elements around the element being inspected, until all
			are sorted/in their proper place, causing an O(n^2)
			asymptotic complexity.

	Quick Sort:	implemented in-place. Pivot point was chosen to be at
			the midpoint of the array. List is reordered so that
			elements are moved either to the left or right of the
			pivot point. The function recursively continues,
			passing in new values for it's left and rights to
			calculate a new pivot until list is sorted. It has a
			best case complexity of O(nlogn), and worst or O(n^2)
			in the case of an already sorted list.

Sources:
	Discussed QuickSort with Jessica Morales