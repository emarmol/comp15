#include "WordList.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "hashtable.h"
using namespace std;


WordList::WordList() {
}

WordList::~WordList() {

}

//                                                                              
// read_lyrics                                
//   purpose: read in song data from a disk file
//   arguments: the name of the file, bool to ask for progress status
//   returns: nothing
//   does: calls a function each time a word is found
//  
void WordList::read_lyrics(const char * filename, bool show_progress) {

        ifstream in(filename);        // creates an input stream      
        int song_count = 0;           // for progress indicator       
        string artist, title, word;
	int count =0;
        // -- While more data to read...                                        
        while ( ! in.eof() )
        {
	    //push back songs constructor
	    songlist.push_back(song());

	    //push back SongData to top ten
	    top_ten.push_back(SongData());

	    //set top ten songs to point to songlist 
	    top_ten[count].pointer = &songlist;

	    // -- First line is the artist                                  
	    getline(in, artist);
	    if (in.fail()) break;

	    songlist[count].artist = artist;

	    // -- Second line is the title                                  
	    getline(in, title);
	    if (in.fail()) break;

	    songlist[count].title = title;

	    if ( show_progress )
	    {
		song_count++;
		if (song_count % 10000 == 0) {
                                cout << "At "       << song_count <<
                                        " Artist: " << artist     <<
                                        " Title:"   << title << endl;
                        }
                }
                // -- Then read all words until we hit the                      
                // -- special <BREAK> token  

                while ( in >> word && word != "<BREAK>" ) {
		    // -- Found a word 
		    // create song lyrics array

		    songlist[count].lyrics.push_back(word);
 		    word = alpha_only(word);
		    table.insert(word, &top_ten);
                }
                // -- Important: skip the newline left behind                   
                in.ignore();
        }
}

//                                                                              
// alpha_only                                                                   
//   purpose: converts a string to lowercase and alphabetic characters          
//            only. E.g., "Bang!" becomes "bang"                                
//   arguments: a string                                                        
//   returns: the alpha-only string                                             
//   does: converts the string                                                  
//                                                                              
string WordList::alpha_only(string s){
        ostringstream ss;
        for (size_t i=0;i<s.length();i++) {
                if (isalnum(s[i])){
                        ss << (char)(tolower(s[i]));
                }
        }
        return ss.str();
}

void WordList::search() {
    string word = "";
    SongData first;
    // cin >> word;

    while (word != "<BREAK>") {
	//find top ten songs in hashtable
	cin >> word;
	word = alpha_only(word);

	//find word in HashTable
//	vector<SongData> *HT_song = table.find(word);

	//cout << HT_song->pointer->at(0).artist;

//	if (HT_song == NULL ) { cerr<< "null man\n"; }
//	cerr << table.find(word)->at(1).pointer->at(1).artist;
//	cerr << "found word?\n";

/*	int min = (*HT_song)[0].wordCount;
	cerr << "min\n";

	//organize the top ten list
	for (int i=0; i< HT_song->size(); i++) {
	int wc = HT_song->at(i).wordCount;
	if (min > wc) {
	first = HT_song->at(i);
	min = wc;
	}	    
	}*/

	if (first.pointer != NULL ) {
	    for (int i=0; i< 10 ; i++) {
		cout << "Artist: " << 
		    table.find(word)->at(i).pointer->at(i).artist <<" \n";
		cout << "Title: " << 
		    table.find(word)->at(i).pointer->at(i).title << " \n";
		for (int z=0; z<table.find(word)->at(i).pointer->at(i).
			 lyrics.size(); z++) {
		    if (table.find(word)->at(i).pointer->at(i).lyrics[z] == word)  {
			//middle case (5 before & after)
			if(z <= table.find(word)->at(i).pointer->at(i).lyrics[z].size()-5
			   && z >= 5) {
			    for(int k=(z-5); k==(z+5); k++) {
				cout << "Context: "<<
				    table.find(word)->at(i).pointer->at(i).lyrics[k];
			    }
			}
			//there aren't 5 words before (beginning of array)
			if (z < 5) {
			    for(int k=0; k==(z+5); k++) {
				cout << "Context: "<<
				    table.find(word)->at(i).pointer->at(i).lyrics[k];
			    }
		        }
	       
			//there aren't 5 words after (end of array)
		        if (z+5 > table.find(word)->at(i).pointer->at(i).lyrics[z].size()) {
			    for(int k=z; k==table.find(word)->at(i).pointer->at(i).
				    lyrics[z].size(); k++) {
				cout << "Context: "<<
				    table.find(word)->at(i).pointer->at(i).lyrics[k];
			    }
		        }
		    }
		}
	    }	
	}
    }
    cout << "<END OF REPORT>";
}
