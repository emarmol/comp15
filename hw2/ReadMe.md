# ReadMe for COMP 15 HW2 
## Linked Lists

Every assignment you submit you will include a ReadMe file. The name
could be ReadMe, readme, Read-me.txt, readME, ReadMe.md (the “.md”
stands for “markdown,” which allows lightweight formatting) or almost
anything you like that has the word read followed by the word me. Exact
spelling is not important, the contents are.

The purpose of the ReadMe file is the same as the little paper insert
you get in a new appliance -- to give the reader an introduction and
overview of the product.

Your ReadMe file for the assignments **must** include:

1.  The purpose of your program
The purpose of the program is to be able to manipulate the deck according
to what the user wants. The program is able to insert/remove/replace cards
anywhere. Using a singly linked list, the program creates space for inserted
cards. The program is also able to tell the user if a card is in the deck,
and what card is at what index.


2.  List of files with one/or two-line summary
List_linked_list.cpp-Contains the list of cards held by user. Deals with
        the changes made by insertion/deletion/replacement of cards.
List_linked_list.h- Header file that declares public/private variables, in
        the list_linked_list class. Documentation of class' functions.
	Contains definition of the struct for a Card_Node.
hand.cpp- Contains the list of the list_linked_list, and is able to print
        the cards in the hand. Able to create 52 card deck.
hand.h- Header file for the hand class declaring public/private variables.
        Documentation of hand class' functions.
card.cpp- Defines suits and ranks of cards, able to get and set suits and
        ranks. Can compare and copy cards with functions in card.cpp.
card.h- Header file for the card class declaring public/private variables.
        Documentation of card class' functions.

3.  How to compile it (saying "use included Makefile" is ok)
Use the included Makefile

4.  Outline of data structure (depending on the assignment)
The data structure used was the singly linked list. The list contains
a pointer to the head of the list, and next. Head points to the next
pointer. The list can be traversed by setting a node equal to the it's next
pointer.

5.  Outline of algorithm (depending on the assignment)
        insert_at_head-allows addition of a card to the beginning of the list
                        - requires saving the head pointer. Creates new
			  memory space for pointer of card being inserted
			  Changes head to new pointer, and next is old head
        insert_at_tail: allows addition of a card to the end the linked list
                        - Must walk the list and save last card node. Create
			  new space for inserted cards pointer, and set the
			  last card's next to the inserted card. The inserted
			  card points to null.
        insert_at_index: Allows addition of a card to a specific location in
                          the list. Must walk the list to the given index,
			  saving the previous node and the current node.
			  Prev points to the card being inserted, and the
			  card being inserted points to the 'current node'
        remove: Will remove the card specified in the parameter passed in.
                    	- Requires walk the list to find the card that matches
			  card passed in. Save previous and current nodes.
			  Prev points to the current cards next. Returns
			  removed card. 
	replace_from_index: Replaces card at given index. Walks list until finds
			  card and sets card in parameter to the card in index
        remove_from_index: Removes card at specified location. Walks list saving
                	  prev and temp (current node), set prev to point to the
			  current nodes next
        remove_from_head: Removes card at the beginning of the array.
                	- Points current head to next
        remove_from_tail: Removes card at end of list. Saves prev and current node
			  walks list until reaches end, and sets prev to point to
			  current node's pointer (NULL).
        cards_in_hand: Walks list adding how many cards are in hand until
			reaches NULL pointer
	make_empty: Clears all the nodes one by one walking through the list
			- Sets head pointer to NULL
        has_card: check to see if card in parameter can be found in list.
        card_at: Lists card at specified index.

The ReadMe file shows the reader, in a quick glance, what the program is
about and gives a general idea of how it works. For short programs the
readme file will be short, for more complicated programs the readme file
will be longer.

Use outline form rather than long discursive paragraphs. A ReadMe file
is an overview.

There is no correct readme format; within these guidelines, devise your
own style.
