#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <vector>
#include <string>


#define MAX_LOAD_FACTOR 0.7
#define INIT_CAPACITY 10

struct song {
    std::string artist;
    std::string title;
    std::vector<std::string> lyrics;
};

struct SongData {
    //pointer to song
    std::vector<song> *pointer;
    int wordCount;
};

struct HashedWords {
    std::string alpha_word;
    std::vector<SongData> *songs;
};



class HashTable {
public:
    HashTable();
    ~HashTable();

    void insert(std::string word, std::vector<SongData> *song);
    std::vector<SongData> *find(std::string word);
    float load_factor() {return (float)table_count/table_capacity;}

private:
    HashedWords *table;
    void expand();
    int table_capacity;
    int table_count;
};


#endif /*HASHTABLE_H_*/
