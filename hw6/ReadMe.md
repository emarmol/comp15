# ReadMe for COMP 15 HW6
## Song Search 

1.  The purpose is to create a database that provides the user with the
    ability to search a word. The program will provide the top ten songs
    that have the most occurances of that word. The program should print
    each instance of the occurance, with a context of 5 works before
    and 5 words after.

2.
hashtable.h - header file for class to define the hashtable functions
	      which incluude insert, find, and expand. Defines 3 structs
	      		1.song - which is the title, lyrics, and artist
			2.SongData- a pointer to an array of songs,
				and wordCount
			3.HashedWords- the type that makes up the hashtable
				which is a word, and an array of type
				SongData
hashtable.cpp - inserts words into hashtable, finds words returning
		the pointer to where the song is, expands hashtable
		Builds a hashtable of type HashedWords, containing an
		array of type SongData, pointing to an array of songs,
		and wordCount.
WordList.h - header file for class to define the WordList functions
	     which include read_lyrics, alpha_only, and search
WordList.cpp - creates vectors to hold the list of songs, reads in lyrics,
		searches for a word that is typed. Stops searching when
		<BREAK> is typed. Also, turns the word into an alpha_only
		word

3. Use included Makefile

4.  This assignment uses the vector built in library as dynamic arrays
    for song lyrics, songs themselves, and lists of the top ten songs.
    This program also uses hashtables with built in key functions that
    hash strings to different values. The hashtable itself functions
    similarly to a dynamic array, where it will expand when necessary.
    The main data structure used would be the dynamic array, which helps
    with memory efficiency, since it will expand only when necessary. This
    tool is especially useful when dealing with larger databases because
    not all memory will be allocated at once if the a particular search
    renders a small result.

5.  The program will 
	-read a file, storing the lyrics in a dynamic array
    	-hashes the string, immediately storing it into the hashtable.
    	-hashtable insertion function will insert the word. 
	-if a collision occurs with the given hashed location 
	 (using % so it wraps around the capacity of the table)
	 linear probing is used to find a new location, taking
	 the number of attempts into account
	-if table count reaches full capacity, the hashtable expands
	-To search: the program will read in input until the word
	 <BREAK> is typed
	-it will search the top 10 array in search of the words
	  with the highest frequencies
	-program prints out the artist, title, and the context
	 (5 words before and 5 words after the occurance of the
	  searched word)
	- The program should print each occurance of the word

	+Issues with alogirthm:
	- While I originally coded my program with the above ideas in mind
	  my program does not exactly output what it was intended
	- I understand that my vector for songs that contain the word
	  does not hold more than one song
	- My program also seg faults when attempting to access the other
	  songs since they don't exist the way I've stored them
	- My program also does not prioritize the words based on their
	  frequency. The problem with my original implementation of the
	  frequency (or wordCount as I defined it) is that there was no
	  way to initialize it in my array
	- Issue with printing the occurances also arose due to seg faulting

6.  Discussed ideas with Jessica Morales, and Ambika Jayanukamar
