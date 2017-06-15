//
//   QuickSort.h
//   Header File for QuickSort class

#ifndef __Sorting__QuickSort__
#define __Sorting__QuickSort__

#include <iostream>

struct arrayWithLength {
    int length;
    int *arr;
};

class QuickSort {
public:
    QuickSort(); //constructor
    ~QuickSort(); //destructor

    //read in a list of values from stdin
    void readList();

    //sort function
    void sort();

    //print array
    void printArray();

private:
    arrayWithLength sortArray;
    void sort2(arrayWithLength sortArray, int left, int right);
};

#endif /* defined (__Sorting__QuickSort_) */
