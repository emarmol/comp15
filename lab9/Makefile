#
# Makefile for Hashing Lab
#
CXX = clang++
FLAGS = -O0 -g3 -Wall

hectorHash: hector-main.cpp hector.cpp hector.h
	${CXX} ${FLAGS} -o hectorHash hector-main.cpp hector.cpp

clean:
	rm -f hectorHash
	
provide:
	provide comp15 lab9 hector-main.cpp hector.cpp hector.h Makefile
