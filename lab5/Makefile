#
# Makefile for BSTree
#
CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -Wreturn-type -g

BSTree: main.cpp BSTree.cpp BSTree.h
	${CXX} ${FLAGS} -o tree_traversal  main.cpp BSTree.cpp

clean:
	rm -f tree_traversal
	
provide:
	provide comp15 lab5 main.cpp BSTree.cpp BSTree.h Makefile
