#include "List_linked_list.h"

#include <iostream>
#include <cassert>
#include <stdlib.h>

using namespace std;

// hint: in your constructor, you might want to set the head to NULL
List_linked_list:: List_linked_list()
{
    head = NULL;
}

List_linked_list::~List_linked_list()
{
    // delete list by looping through and deleting each node
    while (head != NULL) {
	Card_Node *next = head->next;
	delete head;
	head = next;
    }
    delete head;
}

// copy constructor
List_linked_list::List_linked_list(const List_linked_list& source) {
	// explicit copy constructor necessary because of cards array
	if (source.head == NULL) return; // nothing to do

	head = new Card_Node;
	Card_Node *this_current = head;
	Card_Node *source_current = source.head;

	while (source_current != NULL) {
		// deep copy each Card_Node
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next = new_node;
			new_node->card = source_current->next->card;
		}
		else {
			this_current->next = NULL; // at tail
		}
		source_current = source_current->next;
		this_current = this_current->next;
	}
}

// operator= overload
List_linked_list List_linked_list::operator =(const List_linked_list&
		source) {
	// explicit operator= overload necessary because of cards array

	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}
	// delete all current cards
	while (head != NULL) {
		Card_Node *next = head->next;
		delete head;
		head = next;
	}
	// copy over all cards from source list
	if (source.head == NULL) return *this; // nothing to do

	head = new Card_Node;
	Card_Node *this_current = head;
	Card_Node *source_current = source.head;

	while (source_current != NULL) {
		// deep copy each Card_Node
		this_current->card = source_current->card;
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next = new_node;
		}
		else {
			this_current->next = NULL; // at tail
		}
		source_current = source_current->next;
		this_current = this_current->next;
	}
	return *this;
}

void List_linked_list::print_list()
{
	Card_Node *current = head;
	while (current != NULL) {
		current->card.print_card();
		if (current->next != NULL) {
			cout << ",";
		}
		else {
			cout << "\n";
		}
		current = current->next;
	}
}

void List_linked_list::print_list_int()
{
	Card_Node *current = head;
	while (current != NULL) {
		current->card.print_card_int();
		if (current->next != NULL) {
			cout << ",";
		}
		else {
			cout << "\n";
		}
		current = current->next;
	}
}

int List_linked_list::cards_in_hand()
{
    //Checks if the list is empty, returns no cards in hand
    if(head == NULL) {
	return 0;
    }

    //loops through adding to counter to find how many cards
    int counter = 0;
    Card_Node *temp = head;
    while (temp != NULL) {
	counter++;
	temp = temp->next;
    }
    return counter;
}

void List_linked_list::make_empty()
{
    //loops deleting each node, sets final head to NULL
    while (head != NULL) {
	Card_Node *next = head->next;
	delete head;
	head = next;
    }
    head = NULL;
}

void List_linked_list::insert_at_head(Card c)
{
    //Corner case: If list is empty, inserts card as first one
    if(head == NULL) {
	Card_Node *firstcard = new Card_Node();
	firstcard->card = c;
	head = firstcard;
	head->next = NULL;
    }

    //If not empty list, creates new memory space, and inserts at head
    else {
    	Card_Node *temp = new Card_Node();
    	temp->card = c;
    	temp->next = head;
   	head = temp;
    }
}

void List_linked_list::insert_at_tail(Card c)
{
    //Corner case: If list is empty, inserts card as first one
    if (head == NULL) {
	Card_Node *first = new Card_Node();
	first->card = c;
	head = first;
	head->next = NULL;
    }

    //If not empty, inserts card at tail, walks list until end 
    else {
    	Card_Node *inserting = new Card_Node();
   	 Card_Node *temp = head;
    	inserting->card = c;
    	int num_cards = cards_in_hand();
    	int counter = 0;
   	 while (counter < num_cards-1) {
		temp = temp->next;
		counter++;
    	}

	//Last card points to inserted card, inserted card points to NULL
    	temp->next = inserting;
    	inserting->next = NULL;
    }
}

void List_linked_list::insert_at_index(Card c, int index)
{
    if(index == 0 ) {
	insert_at_head(c);
    }

    //Check is card being inserted is the first card
    else if(head == NULL) {
	Card_Node *firstcard = new Card_Node();
	firstcard->card = c;
	head = firstcard;
	head->next = NULL;
    }
    //Walks the list until reaches index point, keeps track of prev
    else {
    	Card_Node *inserting = new Card_Node();
    	Card_Node *temp = head;
    	Card_Node *prev = head;
    	inserting->card = c;
    	int counter = 0;
    	while (counter < index) {
	     prev = temp;
	     temp = temp->next;
	     counter++;
   	}
	//Prev points to card being inserted, and inserted card points
	//to temp (card in that index before)
   	prev->next = inserting;
   	inserting->next = temp;
    }
}

void List_linked_list::replace_at_index(Card c, int index)
{
    //Corner case: checks to see if card is the firstcard inserted
    if(head == NULL) {
	Card_Node *firstcard = new Card_Node();
	firstcard->card = c;
	head = firstcard;
	head->next=NULL;
    }

    // Walks list, replaces card at given index
    else {
    	Card_Node *temp = head;
    	int counter = 0;
    	while (counter < index) {
		temp = temp->next;
		counter++;
    	}
    	temp->card = c;
    }
}

Card List_linked_list::card_at(int index)
{
    //walks list changing counter by 1 until finds card at index
    Card_Node *temp = head;
    int counter = 0;
    while(temp!=NULL) {
	if(counter == index) {
	    return temp->card;
	}
	temp = temp->next;
	counter++;
    }
    return temp->card;
}

bool List_linked_list::has_card(Card c)
{
    // Compares card passed in with each card in the list 
    Card_Node *temp = head;
    while(temp != NULL) {
	if((temp->card).same_card(c)) {
	    return true;
	}
	temp = temp->next;
    }
    return false;
}

bool List_linked_list::remove(Card c)
{
    //Walks list and compares each card with card passed in, keeps prev
    //If same card, the previous card points to the removed cards next.
    if(head != NULL) {
    	Card_Node *temp = head;
    	Card_Node *prev = head;
    	while(temp != NULL) {
		if((temp->card).same_card(c)) {
	    	     prev->next = temp->next;
		     head = prev;
	    	     return true;
		}
		prev = temp;
		temp = temp->next;
    	}
    }
    return false;
}

Card List_linked_list::remove_from_head()
{
    //corner case: checks if list is empty
    if(head == NULL) {
	exit (EXIT_FAILURE);
    }

    //sets head pointer to next one in list
    Card_Node *temp = head;
    head= temp->next;
    return temp->card;
}

Card List_linked_list::remove_from_tail()
{
   //corner case: checks if list is empty
    if(head == NULL) {
	exit (EXIT_FAILURE);
    }

    else if(head->next == NULL) {
	Card only_card = head->card;
	head = NULL;
	return only_card;
    }

    Card_Node *temp = head;
    Card_Node *prev = head;
    int card_num = cards_in_hand();
    int counter = 0;
    Card removed;

    //isolates the last card in the list,saves prev
    while(counter < card_num-1) {
	prev = temp;
	temp = temp->next;
	counter++;
    }

    //sets prev to the last cards next
    prev->next = temp->next;
    removed = temp->card;
    return removed;
}

Card List_linked_list::remove_from_index(int index)
{
    Card_Node *temp = head;
    Card_Node *prev = head;
    int counter=0;
    Card removed;
    if(index == 0 ) {
	removed = remove_from_head();
    }
    else if(index == cards_in_hand()-1) {
	removed = remove_from_tail();
    }
    else {
    while(temp != NULL) {
	if(counter == index) {
	    removed = temp->card;
	    prev->next = temp->next;
	}
	counter++;
	prev = temp;
	temp = temp->next;
    }
    }
    //returns removed card
    return removed;
}
