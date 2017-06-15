//
//  WordList.h
//  Header File for word list class

#ifndef __Song__Search__
#define __Song__Search__

#include <iostream>
#include <vector>
#include "hashtable.h"

using namespace std;

class WordList {
public:

    WordList();
    ~WordList();
    void search();
    void read_lyrics(const char * filename, bool show_progress);
    string alpha_only(string s);

private:
    vector<song> songlist;
    vector<SongData> top_ten;
    HashTable table;

};

#endif /* defined(__Song__Search__) */
