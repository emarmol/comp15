
#include "hashtable.h"
#include "hashfunc.h"
#include <iostream>

using namespace std;

HashTable::HashTable() {
    table = new HashedWords[INIT_CAPACITY];
    //initializes all spaces in array to empty string
    table_capacity = INIT_CAPACITY;
    table_count = 0;
    for (int i=0; i< INIT_CAPACITY; i++) {
	table[i].alpha_word = "";
	//(*table.songs)->push_back(SongData());
//	for (int j=0; j< table[i].songs->size(); j++) {
	    //(*table[i].songs)[j].pointer = NULL;
	    //(*table[i].songs)[j].wordCount = 0;
//	}
    }
}

HashTable::~HashTable() {
    for (int i=0; i<table_capacity; i++) {
	//delete  table[i].songs;
    }
    delete [] table;
}

void HashTable::insert(string word, vector<SongData> *song) {
    // cerr << "in insert\n";

    //Check load factor to see if must expand
    if (load_factor() > MAX_LOAD_FACTOR) {
	expand();
    }

    //hash the word
    unsigned int hash_value = hash_string(word);
    bool finish_insert = false;
    int attempt = 0;

    //find position in table
    int table_pos = hash_value % table_capacity;

    while (!finish_insert) {
	//if empty space, insert, & change finish_insert to true
	if(table[table_pos].alpha_word == "") {
	    table[table_pos].alpha_word = word;
	    table[table_pos].songs = song;
	    table_count++;

	    //keep track of how many times the word 
	    //appears in each song
/*	    for (int i = 0; i< table[table_pos].songs->size(); i++) {
		(*table[table_pos].songs)[i].wordCount++;
		}*/
	    finish_insert = true;
	}
	//if not empty space, deal with collision
	//with linear probing
	else {
	    attempt++;
	    table_pos = (hash_value + attempt) % table_capacity;
	}
    }
}

void HashTable::expand() {
    //1. create new table with twice the capacity
    HashedWords* temp =  new HashedWords[table_capacity*2];

    //2. initialize new table with what alpha_word is set to
    for(int i=0; i<table_capacity; i++) {
	temp[i].alpha_word = table[i].alpha_word;
	temp[i].songs = table[i].songs;
    }


    //3. swap the new table pointer and the old table pointers using
    //   a temp pointer
    HashedWords *temp2 = table;
    table = temp;
    //4. change the table capacity to twice the capacity
    table_capacity = table_capacity * 2;

    //5. make table_count = 0
    table_count = 0;

    //6. rehash all the old keys (alpha_only words) which you get
    //   by walking the old table (note: you determine whether you have to
    //   rehash if the alpha_only word is not reual to "")
    int attempting=0;
    for(int i=0; i< table_capacity/2; i++) {
	unsigned int hash_value = hash_string(temp2[i].alpha_word);
	int pos = hash_value % table_capacity;

	if(temp2[i].alpha_word != "") {
	    table_count++;
	    attempting++;
	    pos = (hash_value + attempting) % table_capacity;

	    table[pos].alpha_word = temp2[i].alpha_word;
	    table[pos].songs = temp2[i].songs;
	}
	else {
	    
	}
    }
    //7. delete [] the old table
    delete [] temp2;
}


vector<SongData> *HashTable:: find(string word) {

    //hash string to an int
    unsigned int hash_value = hash_string(word);
    int table_pos = 0;
    int attempt = 0;

    //search for the entry in the hash table, linear probe method
    bool done_searching = false;
    bool found_word = false;

     table_pos = hash_value % table_capacity;
    while (!done_searching) {
	//check table pos' alpha_only word
 	//if it is the empty string, finish, word not there

	if(table[table_pos].alpha_word == "") {
	    return NULL;
	}	    
	else if (table[table_pos].alpha_word == word) {  
	   //   else found word, found_word = true, done_searching = true
	   // retrun song's pointer that the position, otherwise return NULL
	    found_word = true;
	    done_searching = true;
	    return table[table_pos].songs;
	}
	else {
	   //   else if the table alpha_only word is not empty
	   //   string, continue searching rehashed vals
	    attempt++;
	    table_pos = (hash_value + attempt) % table_capacity;
	}
    }
    return NULL;
}
