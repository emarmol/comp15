#
# Makefile for Heap
#
CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -Wreturn-type -g

heapSort: main.cpp heap.cpp heap.h
	${CXX} ${FLAGS} -o heapSort main.cpp heap.cpp

clean:
	rm -f heapSort
	
provide:
	provide comp15 lab8 main.cpp heap.cpp heap.h Makefile
