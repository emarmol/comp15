//
//   QuickSort.cpp
//   Sorts integers using the QuickSort algorithm

#include "sort3.h"

using namespace std;

QuickSort::QuickSort() { //constructor
    sortArray.length = 0;
    sortArray.arr = NULL;
}

QuickSort::~QuickSort() { //destructor
    delete [] sortArray.arr;
}

void QuickSort::readList() {
    int currentCapacity = 10;
    sortArray.arr = new int[currentCapacity];
        
    while (cin >> sortArray.arr[sortArray.length]) {
	++sortArray.length;
	if (sortArray.length==currentCapacity) {
	    int *temp = new int[currentCapacity*2];
	    for (int i=0;i<currentCapacity;i++) {
		temp[i] = sortArray.arr[i];
	    }
	    delete [] sortArray.arr;
	    sortArray.arr = temp;
	    currentCapacity *= 2;
	}
    }
}

void QuickSort::sort() {
    int left = 0;
    int right = sortArray.length -1;
    QuickSort::sort2(sortArray, left, right);
}

void QuickSort::sort2(arrayWithLength sortArray, int left, int right) {
    int tempRight = right;
    int tempLeft =left;
    int temp=0;
    //sets pivot to the midpoint of the array
    int pivot = sortArray.arr[(left+right)/2];
     while(tempLeft <= tempRight) {

	//moves to correct starting spot for right & left indices
	while (sortArray.arr[tempRight] > pivot) {
	    tempRight--;
	}
	while (sortArray.arr[tempLeft] < pivot) {
	    tempLeft++;
	}

	//swaps two elements if they are on the wrong side of pivot
	if (tempLeft <= tempRight) {
	    temp = sortArray.arr[tempRight];
	    sortArray.arr[tempRight] = sortArray.arr[tempLeft];
	    sortArray.arr[tempLeft] = temp;
	    tempLeft++;
	    tempRight--;
	}
    }

    //recursion: called for left half of array
    if(left < tempRight) {
	sort2(sortArray, left, tempRight);
     }

    //recursion called for right half of array
    if (tempLeft < right ) {
	sort2(sortArray, tempLeft,right);
     }
}

void QuickSort::printArray() {
    // prints out the integers in sorted order
    for (int i = 0; i<sortArray.length; i++) {
	std::cout << sortArray.arr[i] << std::endl;
    }
}
