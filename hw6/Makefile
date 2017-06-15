#
# Makefile for SongSearch, Assignment 6
#
CXX = clang++
FLAGS = -Wall -g3

songsearch: WordList.h  WordList.cpp hashtable.h hashtable.cpp  main.cpp hashfunc.h hashfunc.cpp
	${CXX} ${FLAGS} -o songsearch WordList.cpp hashtable.cpp main.cpp hashfunc.cpp

clean:
	rm -f songsearch

provide_design:
	provide comp15 hw6_design songsearch_design.txt

provide:
	provide comp15 hw6 WordList.h WordList.cpp hashtable.h hashtable.cpp main.cpp hashfunc.h hashfunc.cpp Makefile

