// HookBook Social Network
// Lab 1 -- Data Strucures (COMP 15)
// Spring 2014

#ifndef HOOKBOOK_H
#define HOOKBOOK_H

#include<iostream>

using namespace std;

//kept small for tesing purposes
//used in both friend initialization
//and pirate initialization

const int INIT_CAPACITY = 5;

struct Pirate
{
    int memberID;
    string name;
    int* friendList;
    int friendCount;
    int friendCapacity;
};

class HookBook{

  public:
    /* constructor */
    HookBook();

    /* Adds a new pirate to HookBook, probably the member should
       be created by the hookbook system, for now it is sent in
       from main, the pirate starts with no friend*/
    
    bool addPirate(int member, string memberName);


    /* Prints the values in the list in ascending order. */
    /* This method is "const", which is a promise to the compiler
     that it won't change the value of any private variables. */
    void print() const;


    //the function you will write
    bool addFriend(int memID, int friendID);
    
    /* destructor */
    ~HookBook();
	
private:
 
    Pirate* hbook;
    int pirateCount;
    int currentCapacity;
    bool expandPirates();
 
};

#endif
