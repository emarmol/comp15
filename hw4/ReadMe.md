# ReadMe for COMP 15 HW4
## Binary Search Tree Assignment 

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
The purpose of this program is to use recursion to insert/delete
nodes from a binary tree.

2.  List of files with one/or two-line summary
BinarySearchTree.cpp- contains the functions to implement the class:
		insert/remove, min/max, contains, print
BinarySearchTree.h- header file for BinarySearchTree Class, contains
		Node struct and functino definitions
PrettyPrint.cpp- prints binary tree in a visually appealing manner

3.  How to compile it (saying "use included Makefile" is ok)
Use included Makefile

4.  Outline of data structure (depending on the assignment)
The binary search tree could be implemented as an array, so it can be
considered an abstract data type. This project uses a linked list
implementation for the data structure, where there are left/right
pointers for each node that contains data and a counter.

5.  Outline of algorithm (depending on the assignment)
To insert: to insert, must check if node is the first node (root)
	-Since using recursion, the base case if set to when the node
	is found to be null.
	- Create a new Node() to insert setting if based on parent
	- Check if node already exists in tree, and increase count
	- If none of the cases apply, resurses through tree left/right
	depending on value until base case is satisfied
To remove: - Check if there are no nodes to remove
	- Check if the value is/is not in tree
	- Traverses through tree based off data/value relation to find
	the node you are trying to remove
	- Case if is leaf, removes node to left or right of parent.
	- Case if has one child to right, checks nodes placement
	linked list deletion (bypass) 
	- Case if has one child to left, same as right
	- Case if node has two children: finds min to right branch
		+ Finds parents
		+ Set node data to min data
		+ recurses through tree depending on node/value placement
Min/Max: Because it's a binary search tree, the value furthest to the left
	will be the minimum, and the value furthest to the right will be max.

Use recursion to find other values such as tree height/node count
Implementation: traverse tree left/right adding value needed each time
	function is called

6.  A list of people who materially helped you on the assignment. If
    you worked with a friend and you shared ideas, you need to 
    list that person, e.g., "Josh Whedon helped me on this assignment".
    You do not need to list TAs, or professors, but you may feel free
    to do so.
Discussed with Jessica Morales

The ReadMe file shows the reader, in a quick glance, what the program is
about and gives a general idea of how it works. For short programs the
readme file will be short, for more complicated programs the readme file
will be longer.

Use outline form rather than long discursive paragraphs. A ReadMe file
is an overview.

There is no correct readme format; within these guidelines, devise your
own style.
