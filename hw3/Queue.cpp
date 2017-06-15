/*
 * Queue.cpp
 *
 */

#include <iostream>
#include "Queue.h"
#include "stdlib.h"

// TODO: Student writes this class
Queue::Queue() {
    capacity = QUEUE_INIT_CAPACITY;
    size = 0;
    front = 0;
    back = 0;
    queue_array = new Student[QUEUE_INIT_CAPACITY];
}

Queue::~Queue() {
    delete [] queue_array;
}

void Queue::enqueue(Student c) {

    //last position gets student
    queue_array[back] = c;

    //change back counter
    back = (back+1) % capacity;
    size++;
    if(capacity == size) {
	expand();
    }

}

Student Queue::dequeue() {
    //Makes sure not to dequeue from empty array
    if(size == 0) {
	exit (EXIT_FAILURE);
    }

    //sets temp to front item to return
    Student temp = queue_array[front];

    //front moves to next position
    front = (front+1) % capacity;

    //decrease size
    size--;
    return temp;
}

bool Queue::is_empty() {
    if(front == back)
	return true;
    return false;
}

void Queue::expand() {
    //allocates new space with twice the capacity
    Student *temp = new Student[capacity*2];

    //copies over elements from queue_array into temp
    for(int i=0; i<size; i++) {
	temp[i] = queue_array[(front+i)%capacity];
    }

    //delete queue_array
    delete [] queue_array;

    //point queue_array to temp
    queue_array = temp;

    //reinitialize front and back
    front = 0;
    back = capacity;

    //change capacity
    capacity*=2;
}
