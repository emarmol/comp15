# ReadMe for COMP 15 HW3
## ISIS Course Roster and Waitlists

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
The purpose of this program is to simulate Tufts' SIS program by
enrolling, waitlisting when classes are full, waitlisting nonmajors
automatically, and dropping students from a class.

2.  List of files with one/or two-line summary
IsisCourse.cpp -definiton functions for enroll, drop, waitlist position,
		status, printing
IsisCourse.h - header file defining the IsisCourse class
Queue.cpp - definition functions for enqueue, dequeue, and expand
Queue.h - header file defining the Queue class for the waitlists
Set.cpp - definition of add/drop, is enrolled, and print functions 
Set.h - header file defining the Set class for the roster
Student.h - header filed defining the student structs; has name/major

3.  How to compile it (saying "use included Makefile" is ok)
Use included Makefile

4.  Outline of data structure (depending on the assignment)
Two abstract data structures used:
	Set: Simple list with no repeated elements
	Queue: First-in-last-out behavior, change front/back indices.
The data structure used to implement the two ADT's is a dynamic array.
It grows when it's capacity is reached. 

5.  Outline of algorithm (depending on the assignment)
	+ For enqueue/dequeue the front and back indices were changed to
		accomodate adding or taking away a element, circular 
		implementation.
	+ Dynamic array expands when capacity reaches, makes new array,
		and copies over all elements; use % to wrap around array
	+ To search the list a temp queue is made, dequeue first students
		and save student to enqueue onto temp queue. Repeat process 
		to dequeue from temp and enqueue to proper waitlist queue. 
		Isolates needed student from waitlist.
	+ Searching the list is used in waitlist_position, drop_student,
		status, and print_list
	+ For enrolling: must check capacity isn't reached, and if student 
		is a major or not to add to proper waitlist.
	+ Update enrollments checks to see if the number of students is
		less than the capacity. If so, add from major_waitlist first 
		until empty, then other_waitlist. If both empty, breaks 
		from while loop.
	+ Status uses searching algorithm, and returns the status if student
		is found in the proper waitlist depending on if they are 
		a major or not
	+ Print_list and waitlist_postion have same general implementation
		When student searched for/isolated print couts the numbered 
		student and waitlist_position returns the status if student 
		found on list.

6.  A list of people who materially helped you on the assignment. If
    you worked with a friend and you shared ideas, you need to 
    list that person, e.g., "Josh Whedon helped me on this assignment".
    You do not need to list TAs, or professors, but you may feel free
    to do so.
	Discussed general ideas/concepts for enroll_student function
	with Jessica Morales.

The ReadMe file shows the reader, in a quick glance, what the program is
about and gives a general idea of how it works. For short programs the
readme file will be short, for more complicated programs the readme file
will be longer.

Use outline form rather than long discursive paragraphs. A ReadMe file
is an overview.

There is no correct readme format; within these guidelines, devise your
own style.
