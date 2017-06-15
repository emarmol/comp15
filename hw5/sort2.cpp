//
//  InsertionSort.cpp
//  Sorts integers using the InsertionSort algorithm

#include "sort2.h"

using namespace std;

InsertionSort::InsertionSort() { //constructor
    sortArray.length = 0;
    sortArray.arr = NULL;
}

InsertionSort::~InsertionSort() { //destructor
    delete [] sortArray.arr;
}

void InsertionSort::readList() { //read in list (from Selection Sort readList)
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

void InsertionSort::sort() {

    //nest for and while loop compares previous element to current element
    //swaps if necessary
    for (int i=1; i<sortArray.length; i++) {
	int j = i;
	while(sortArray.arr[j-1] > sortArray.arr[j]) {
	    int temp = sortArray.arr[j-1];
	    sortArray.arr[j-1] = sortArray.arr[j];
	    sortArray.arr[j] = temp;
	    j = j-1;
	}
    }
}

void InsertionSort::printArray() {
    // prints out the integers in sorted order
    for (int i = 0; i<sortArray.length; i++) {
	std::cout << sortArray.arr[i] << std::endl;
    }
}
