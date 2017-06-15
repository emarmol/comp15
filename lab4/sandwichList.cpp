/* sandwichList.cpp
 * Comp 15 
 * Spring 2014 
 * Lab 4
 */

#include "sandwichList.h"


SandwichList::SandwichList()
{
	capacity = INITIAL_SIZE;
	orders = new Order[INITIAL_SIZE];
	orderCount = 0;

	back = 0;
	front = 0;
}

bool SandwichList::isEmpty()
{
	if (size() == 0)
		return true;
	else
		return false;
}


int SandwichList::size()
{
        return orderCount;
        // you could use the following arithmetic (but be careful):
	//return (back - front + capacity) % capacity;
}

//function to remove Order from the front of the queue
Order SandwichList::dequeue()
{

// TODO: Students write code here
    /*if(isEmpty()) {
	std::exit(1);
	}*/

    Order curr = orders[front];

    if(front < capacity-1) {
	    front++;

    }
    else { front = 0; }
	    orderCount--;
    return curr;
}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::enqueue(const Order& sw)
{
// TODO: Students write code here
    if (capacity == size()) {
	expandList();
    }
    //if (isEmpty()) {
//	std::exit(1);
    //    }
    orders[back] = sw;

    if(back<capacity-1) {
    	back++;
    }
    else {
	back = 0;
    }
    orderCount++;
}

//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{
// TODO: Students write code here
    //int i=-1;
    Order *new_orders = new Order[capacity*2];
    new_orders[0] = orders[front];
    for(int i=1; i<size();i++) {
	    if(front < capacity-1) {
		front++;
	   }
	  else {
		    front=0;
	   }
	new_orders[i] = orders[front];
    }
	front = 0;
	back = size();
	delete [] orders;
	orders = new_orders;
        capacity = capacity * 2;
}

void SandwichList::printOrder(Order s)
{
	cout << s.sandwich << " " << s.customerName << " " << s.orderNbr << " " << s.fries;
	cout << endl;
}



