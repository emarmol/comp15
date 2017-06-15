/*
 * IsisCourse.cpp
 *
 */

#include <iostream>
#include "IsisCourse.h"

IsisCourse::IsisCourse() {
    class_capacity = 0; // no students allowed in yet
}

IsisCourse::IsisCourse(int init_capacity) {
    // TODO: Student writes code here
    class_capacity = init_capacity;
}

IsisCourse::~IsisCourse() {
    // nothing to do
}

void IsisCourse::set_class_cap(int cap) {
	class_capacity = cap;
	if (roster.size() < class_capacity) {
		update_enrollments();
	}
}

IsisCourse::ENROLLMENT_STATUS IsisCourse::enroll_student(Student s) {
    // See the enrollment logic from the assignment handout or
    // the IsisCourse.h file!
    // TODO: Student writes code here
    if(class_capacity <= get_roster_size()){	//checks if there is no room
	if(s.major) {
	    major_waitlist.enqueue(s);		//majors added to waitlist
	    return MAJOR_WAITLIST;
	}
	else {
	    other_waitlist.enqueue(s);	     //nonmajors added to waitlist
	    return OTHER_WAITLIST;
	}
    }
    else {
	//if there is room on roster, add all majors
	if(s.major){
	    roster.add(s);
	    return ENROLLED;
	}
	else {
	//all nonmajors go to waitlist automatically
	    other_waitlist.enqueue(s);
	    return OTHER_WAITLIST;
	}
    }
}

bool IsisCourse::drop_student(Student s) {
	bool found_student = false; // if we find the student to drop
	Queue temp_queue;
	// TODO: Student writes code here
	if (roster.is_enrolled(s))
	    found_student = true;

	else if (s.major) {
	    //dequeues from major_waitlist to temp_waitlist
	    while(!major_waitlist.is_empty()) {
		    Student curr = major_waitlist.dequeue();
		    temp_queue.enqueue(curr);	    
	    }	
	    //finds student and dequeues to drop when recopying from
	    //temp_queue back to major_waitlist
	    while(!temp_queue.is_empty()) {
		Student curr = temp_queue.dequeue();
		major_waitlist.enqueue(curr);
		if((curr.name == s.name) && curr.major == s.major)
			major_waitlist.dequeue();
	    }
	}	
	else {	//student is not a major or enrolled already
	    while(!other_waitlist.is_empty()) {
		Student curr = other_waitlist.dequeue();
		temp_queue.enqueue(curr);
	    }	
	    while(!temp_queue.is_empty()) {
		Student curr = temp_queue.dequeue();
		other_waitlist.enqueue(curr);
		if((curr.name == s.name) && (curr.major == s.major))
		    other_waitlist.dequeue();
	    }
	}
	if(found_student) {
	    roster.drop(s);
	    // if we dropped a student, there should be room on
	    // the roster
	    update_enrollments();
	}
	return found_student;
}

int IsisCourse::waitlist_position(ENROLLMENT_STATUS status, Student s) {
    // TODO: Student writes code here
    Queue temp_queue;
    int pos = 1;
    int i = 1;
    if(status == NONE)
	return -1;

    else if(status == ENROLLED)
	return 0;

    else if(status == MAJOR_WAITLIST) {
	while(!major_waitlist.is_empty()) {
	    Student curr = major_waitlist.dequeue();
	    temp_queue.enqueue(curr);
	    if((curr.name == s.name) && (curr.major == s.major)){
		pos = i;
	    }
	    i++;
	}
	while(!temp_queue.is_empty()) {
	    Student s = temp_queue.dequeue();
	    major_waitlist.enqueue(s);
	}
	return pos;
    }

    else if(status ==OTHER_WAITLIST) {
	while(!other_waitlist.is_empty()) {
	    Student curr = other_waitlist.dequeue();
	    temp_queue.enqueue(curr);
	    if((curr.name == s.name) && (curr.major == s.major)){
		pos = i;
	    }
	    i++;
	}
	while(!temp_queue.is_empty()) {
	    Student s = temp_queue.dequeue();
	    other_waitlist.enqueue(s);
	}
	return pos;
    }
    return -1;
}

IsisCourse::ENROLLMENT_STATUS IsisCourse::status(Student s) {
    // returns an ENROLLMENT_STATUS that says which list
    // (or none) that the student is on.
    // TODO: Student writes code here
    IsisCourse::ENROLLMENT_STATUS stat = NONE;
    Queue temp_queue;
    if(roster.is_enrolled(s)) 
	return ENROLLED;

    else if (s.major) {
	//if is major, checks major_waitlist, if found when dequeued,
	//returns MAJOR_WAITLIST after finishing and recopying from
	//temp to major_waitlist again
	while(!major_waitlist.is_empty()) {
	    Student curr = major_waitlist.dequeue();
	    temp_queue.enqueue(curr);
	    if((curr.name == s.name) && (curr.major == s.major)){
		stat = MAJOR_WAITLIST;
	    }
	}
	while(!temp_queue.is_empty()) {
	    Student curr = temp_queue.dequeue();
	    major_waitlist.enqueue(curr);
	}
	return stat;
    }
    else if (!s.major) {
	//checks other_waitlist for student passed in
	while(!other_waitlist.is_empty()) {
	    Student curr = other_waitlist.dequeue();
	    temp_queue.enqueue(curr);
	    if((curr.name == s.name) && (curr.major == s.major)){
		stat=OTHER_WAITLIST;
	    }
	}
	//recopies from temp_queue back to other_waitlist
	while(!temp_queue.is_empty()) {
	    Student curr = temp_queue.dequeue();
	    other_waitlist.enqueue(curr);
	}
	return stat;
    }
       return NONE;
}

void IsisCourse::print_list(ENROLLMENT_STATUS status) {
	Queue *waitlist_queue;
	Queue temp_queue;
	if (status == ENROLLED) {
		roster.print_class();
		return;
	}
	if (status == MAJOR_WAITLIST) {
		waitlist_queue = &major_waitlist;
	}
	else {
		waitlist_queue = &other_waitlist;
	}
	// now handle printing the queue
	// TODO: Student writes code here
	if(status == MAJOR_WAITLIST) {
	    int i = 1;
	    //dequeue each student from major_waitlist, enqueue onto
	    //temp_queue. Prints dequeued students in order.
	    while(!major_waitlist.is_empty()) {
		    Student s = major_waitlist.dequeue();
		    temp_queue.enqueue(s);
		    std::cout << i << ". " << s.name
			 << "\n";
		    i++;
	    }
	    //enqueues students back onto major_waitlist
	    while(!temp_queue.is_empty()) {
		Student s = temp_queue.dequeue();
		major_waitlist.enqueue(s);
	    }
	}

	else if(status == OTHER_WAITLIST) {
	    int i = 1;
	    while(!other_waitlist.is_empty()) {
		    Student s = other_waitlist.dequeue();
		    temp_queue.enqueue(s);
		    std::cout << i << ". " << s.name
			 << "\n";
		    i++;
	    }
	    //enqueues students back onto other_waitlist
	    while(!temp_queue.is_empty()) {
		Student s = temp_queue.dequeue();
		other_waitlist.enqueue(s);
	    }
	}
}

void IsisCourse::update_enrollments() {
    // put students from the waitlists into the class
    // in priority (majors first, then others), up to
    // the class capacity.

    // TODO: Student writes code here
    while(roster.size() < class_capacity) {
	//add from major_waitlist first
	if(!major_waitlist.is_empty()) {
	    Student s =  major_waitlist.dequeue();
	    roster.add(s);
	}
	//if not more on major_waitlist add from nonmajors
	else if (!other_waitlist.is_empty()) {
	    Student s2 = other_waitlist.dequeue();
	    roster.add(s2);
	}
	// if no one left of waitlist, break while loop
	else {
	    break;
	}
    }
}


