# ReadMe for COMP 15 HW1 
## Dynamic Arrays

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
anywhere. The program's dynamic array takes into account if more space
is needed in the list of cards. It will also tell the user what cards are
or are not in the deck, and prints the cards.

2.  List of files with one/or two-line summary
List_dynamic_array.cpp-Contains the list of cards held by user. Deals with
	the changes made by insertion/deletion/replacement of cards.
List_dyanmic_array.h- Header file that declares public/private variables, in
	the list dynamic array class. Documentation of class' functions.
hand.cpp- Contains the list of the list_dynamic_array, and is able to print
	the cards in the hand. Able to create 52 card deck.
hand.h- Header file for the hand class declaring public/private variables.
	Documentation of hand class' functins.
card.cpp- Defines suits and ranks of cards, able to get and set suits and
	ranks. Can compare and copy cards with functions in card.cpp.
card.h- Header file for the card class declaring public/private variables.
	Documentation of card class' functinos.
3.  How to compile it (saying "use included Makefile" is ok)
Use included Makefile

4.  Outline of data structure (depending on the assignment)
The data structure used is a dynamic array, which grows as needed.
The amount by which the array increases is twice its original capacity.
Dynamic array will be implemented only if the cards_held is equal to the
hand_capacity.

5.  Outline of algorithm (depending on the assignment)
Functions written in the List_dynamic_array:
	insert_at_head-allows addition of a card to the beginning of the array
			- requires copying all cards and moving them one space
			to the right.
	insert_at_tail: allows addition of a card to the end the array
			- must expand cards held by one
	insert_at_index: Allows addition of a card to a specific location in
			the array. Must copy and move all cards on space to
			the right.
	remove: Will remove the card specified in the parameter passed in.
		-Requires all cards to shift to the left, and the cards_
		held to be decreased by one.
	remove_at_index: Removes card at specified location. Calls remove
		card passing in the card at the location as the parameter.
	remove_at_head: Removes card at the beginning of the array.
		-Calls the remove() function passing in first card only.
	remove_at_tail: Removes card at end of array. Calls remove() also.
	expand: Will grow the array by twice it's original size.
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

