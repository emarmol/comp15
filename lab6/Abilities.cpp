/*
 * Abilities.cpp
 *
 *  Created on: Oct 17, 2014
 *      Author: Chris Gregg
 */

#include "Abilities.h"

using namespace std;

Abilities::Abilities() {
	// start with only your hand
	head = new AbilityNode();
	head->ability.strength = 1;
	head->ability.weapon = "hand";
	head->next = NULL;
}

// copy constructor

Abilities::Abilities(const Abilities &source) {
    // TODO: Students write code here
    //make new list

    Abilities *newlist = new Abilities();
    //newlist->head = source.head;
    
    AbilityNode *prev = NULL;
    AbilityNode *curr = source.head;
    while(curr != NULL) {
	prev = curr;
	AbilityNode *newNode = new AbilityNode();
    	newNode->ability = curr->ability;
    	newNode->next = curr->next;
	curr = curr->next;
    }
    //source = newlist;
}


// assignment (=) overload
Abilities &Abilities::operator=(const Abilities &source) {
	// TODO: Students write code here

    //delete old data
    deleteList();
/*
 
    //same copy constructor to create new list
    Abilities templist = new Abilities();
    AbilityNode *temp = source->head;
    while(temp != NULL) {
	AbilityNode *newNode = new AbilityNode();
    	newNode->ability = source->ability;
    	newNode->next = source->next;
	temp = temp->next;
    }
    return templist;*/
}

Abilities::~Abilities() {
	deleteList();
}

void Abilities::deleteList() {
	// TODO: Students write code here
   AbilityNode *curr = head;
   while(curr != NULL) {
	delete head;
	curr = curr->next;
	head = curr;
    }
}

void Abilities::updateAbility(std::string name, int amount) {
	AbilityNode *curr = head;
	AbilityNode *prev = NULL;

	while (curr != NULL) {
		if (curr->ability.weapon == name) {
			// found the node to update
			curr->ability.strength = amount;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	// not found, create new node to populate
	curr = new AbilityNode();
	curr->ability.weapon = name;
	curr->ability.strength = amount;
	curr->next = NULL;

	if (prev==NULL) {
		// at head
		head = curr;
	}
	else {
		prev->next = curr;
	}
}

int Abilities::getStrength(std::string name) {
	// returns -1 if the name does not exist in the list
	AbilityNode *curr = head;
	while (curr != NULL) {
		if (curr->ability.weapon == name) {
			return curr->ability.strength;
		}
		curr = curr->next;
	}
	return -1;
}

int Abilities::abilityCount() {
	AbilityNode *curr = head;
	int count=0;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

Ability &Abilities::abilityByIndex(int index) {
	// does not do error checking on index!
	AbilityNode *curr = head;
	for (int i=0;i<index;i++) {
		curr = curr->next;
	}
	return curr->ability;
}

void Abilities::printAbilities() {
	// walk the list and print all weapons and abilities
	AbilityNode *curr = head;
	while (curr != NULL) {
		cout << "\t" << curr->ability.weapon << " : "
				<< curr->ability.strength << "\n";
		curr = curr->next;
	}
}

int Abilities::totalStrength() {
	int totalStrength = 0;

	// walk the list and calculate total strength
	AbilityNode *curr = head;
	while (curr != NULL) {
		totalStrength += curr->ability.strength;
		curr = curr->next;
	}
	return totalStrength;
}
