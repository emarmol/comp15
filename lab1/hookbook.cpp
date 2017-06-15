#include "hookbook.h"

HookBook::HookBook()
{
    hbook = new Pirate[INIT_CAPACITY];
    currentCapacity = INIT_CAPACITY;
    pirateCount = 0;
}


    /* Adds a new pirate to HookBook, probably the member should
       be created by the hookbook system, for now it is sent in
       from main, friends is a pointer to a dynamic array we
       copy it to the hookbook data structure, if it is null the pirate
       has no friend*/
    
bool HookBook::addPirate(int member, string memberName)
{
    //check to see if we need to expand to add
    if(pirateCount >= currentCapacity)
    {
            // check to see if expand worked
            if(!expandPirates())
            {
                return false;
            }
    }
    //made it here so we can add a pirate
    hbook[pirateCount].memberID = member;
    hbook[pirateCount].name = memberName;
    hbook[pirateCount].friendList = NULL;
    hbook[pirateCount].friendCount = 0;
    hbook[pirateCount].friendCapacity = 0;
    pirateCount++;
    return true;
    
    
}

    /* Prints the values in the list in ascending order. */
    /* This method is "const", which is a promise to the compiler
     that it won't change the value of any private variables. */
void HookBook::print() const
{
    cout << "There are " << pirateCount << " pirates in the system." << endl;
    for (size_t i = 0; i < pirateCount; i++) {
        cout << "Pirate: " << hbook[i].name << " with memberID: "
             << hbook[i].memberID << " has friends ";
        
        for(size_t j = 0; j < hbook[i].friendCount; j++)
        {
            cout << hbook[i].friendList[j] << " ";
        }
        
        cout << endl;
        
    }
}

    
 
//the function you will write you may have an empty list to start
bool HookBook::addFriend(int memID, int friendID)
{
	// TODO: Students write code here
	for(int i=0; i<pirateCount; i++){
		if(memID == hbook[i].memberID) {
			if(hbook[i].friendCount == hbook[i].friendCapacity) {
				//Expand friendList array
				int* newArray = new int[(hbook[i].friendCapacity)*2];
				if(newArray == NULL){	//check if empty list
				     return false;
				}
				for(int j=0; j<hbook[i].friendCount; j++){
					newArray[j] = hbook[i].friendList[j];
				}
				delete [] hbook[i].friendList;
				hbook[i].friendList = newArray;
				hbook[i].friendCapacity = hbook[i].friendCapacity*2;
			}
			//set friend id to last spot in friendList
			int friends = hbook[i].friendCount;
			hbook[i].friendList[friends] = friendID;
		}
	}
	return true;
}
    
/* destructor */
HookBook::~HookBook()
{
	// TODO: Students write code here
    // first delete all the Pirate data
        for(int i=0; i<hbook[i].friendCount; i++){
        	delete [] hbook[i].friendList;
        }
    // now delete the pirates themselves
        delete [] hbook;

}

bool HookBook::expandPirates()
{
    Pirate* temp = new Pirate[currentCapacity*2];
    if(temp == NULL){
        return false;
    }
    for (size_t i = 0; i < pirateCount; i++) {
        temp[i]=hbook[i];
    }
    delete[] hbook;
    hbook = temp;
    currentCapacity = currentCapacity*2;
    return true;
}

