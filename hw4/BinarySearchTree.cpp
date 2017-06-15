/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include "BinarySearchTree.h"
#include <stdlib.h>

BinarySearchTree::BinarySearchTree() {
    //initialize root to null
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    // walk tree in post-order traversal and delete
    post_order_delete(root);
}

void BinarySearchTree::post_order_delete(Node *node) {
    //use post-order traversal to remove all nodes
    
    //if no nodes in tree
    if(node == NULL) return;

    if(node->left != NULL)
	post_order_delete(node->left);
    if(node->right != NULL)
	post_order_delete(node->right);
    delete node;
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source) {
    // use pre-order traversal to copy the tree
    root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree& BinarySearchTree::operator=
(const BinarySearchTree &source) {
    // check for self-assignment
    if (this != &source) {
	// delete current tree if it exists
	post_order_delete(root);
    }
    // use pre-order traversal to copy the tree
    root = pre_order_copy(source.root);
    // must "return *this"
    return *this;
}

Node * BinarySearchTree::pre_order_copy(Node *node) {
    // uses pre-order traversal

    //if no nodes in tree
    if (node == NULL) return NULL;

    //creates new node to copy
    Node *new_node = new Node();

    //copies node data to new_node
    new_node->data = node->data;
    new_node->count = node->count;
    new_node->left = pre_order_copy(node->left);
    new_node->right =  pre_order_copy(node->right);
    return new_node;
}

int BinarySearchTree::find_min() {
	if (root == NULL) return INT_MIN;
	return (find_min(root)->data);
}

Node *BinarySearchTree::find_min(Node *node) {
    Node *min = NULL;

    //if tree is empty
    if (node == NULL) return NULL;

    //search until reaches last left node
    if(node->left != NULL){
	node = find_min(node->left);
    }
    min = node;
    return min;

}

int BinarySearchTree::find_max() {
    if (root==NULL) return INT_MAX;
    return (find_max(root)->data);
}

Node *BinarySearchTree::find_max(Node *node) {
    Node *max = NULL;

    //if tree is empty
    if(node == NULL) return NULL;

    //search until reaches last right node
    if(node->right != NULL) {
	node = find_max(node->right);
    }
    max = node;
    return max;
}

bool BinarySearchTree::contains(int value) {
    if(root == NULL) return false;
    return contains(root, value);
}

bool BinarySearchTree::contains(Node *node, int value) {
    //if no nodes in tree
    if (node == NULL) return false;

    //base case: if node is equal to value
    if(node->data == value)
	return true;
    
    //recurses left if value less than node data
    if(value < node->data){
	return contains(node->left, value);
    }

    //recurses right if value greater than node data
    if(value > node->data) {
	return contains(node->right, value);
    }
    return false;
}

void BinarySearchTree::insert(int value) {
	insert(root,NULL,value);
}

void BinarySearchTree::insert(Node *node,Node *parent, int value) {
    //if no nodes in tree
    if (root == NULL && parent == NULL) {
	root = new Node();
	root->data = value;
	parent = NULL;
	root->count = 1;
    }

    //base case: if node is null, check which side of parent
    //the new node shoudl be added to
    else if(node == NULL) {
	if(parent->data > value) {
		node = new Node();
		node->data = value;
		parent->left = node;
		node->count = 1;
	}
	else {
		node = new Node();
		node->data = value;
		parent->right = node;
		node->count = 1;
	}
    }

    //if node already exists in tree, increment count
    else if(node->data == value) {
	node->count = node->count + 1;
    }

    //inserts depending on node data's relation to value
    //changes parent to node each traversal
    else {
	if(node->data < value) {
	    parent=node;	
	    insert(node->right, parent, value);
	}
	else {
	    parent = node;
	    insert(node->left, parent, value);
	}
    }
}

bool BinarySearchTree::remove(int value) {
	return remove(root,NULL,value);
}

bool BinarySearchTree::remove(Node *node, Node *parent, int value) {
    //If no nodes in tree
    if(node == NULL) return false;

    //if value doesn't exist in tree
    if(!contains(value)) { return false;}

    //traverses to the node depending on data's relation to value
    if(node->data < value) {
	parent = node;
	remove (node->right, parent, value);
	return true;
    }
    if (node->data > value) {
	parent = node;
	remove(node->left, parent, value);
	return true;
    }

    //if is a duplicate node, decrements count
    if(node->count > 1) {
	node->count--;
	return true;
    }

    //if node is a leaf
    if(node->left == NULL && node->right == NULL) {
	if(parent == NULL) {
	    delete root;
	    root = NULL;
	    return true;
	}
	Node *temp = parent;
	//checks is node is to left or right of parent
	if(temp->left == node) {
	    delete node;
	    temp->left = NULL;
	}
	else if (temp->right == node) {
	    delete node;
	    temp->right = NULL;
	}
	//delete node;
	return true;
    }

    //if node has one child to right
    if (node->left == NULL && node->right != NULL) {
	if (parent == NULL) {
	    	root = node->right;	   
	}
	//checks is node is to left or right of parent
	else if(parent->right == node) {
		parent->right = node->right;
	}
	else if(parent->left == node) {
	    parent->left = node->right;
	}
	delete node;
	return true;
    }

    //if node has one child to left
    if(node->left != NULL && node->right == NULL) {
	if(parent == NULL) {
		root = node->left;
	}

	//checks if node is to left or right of parent
	else if(parent->left == node)
	    parent->left = node->left;
	else if(parent->right == node)
	    parent->right = node->left;
	delete node;
	return true;
    }

    //if node has two children
    if(node->left != NULL && node->right != NULL) {
	//finds min in right branch
	Node *temp = find_min(node->right);
	//finds parent
	parent = find_parent(node, temp);
	//set node data to min data
	node->data = temp->data;
	node->count = temp->count;
	//compares node data to parent data to traverse left/right
	if (node->data > parent->data) {
	    remove(node->left, node, node->data);
	}
	else {
	    remove(node->right, node, node->data);
	}
	return true;
    }
    return false;
}

int BinarySearchTree::tree_height() {
	return tree_height(root);
}

int BinarySearchTree::tree_height(Node *node) {
    //if no tree exists
    if(node == NULL) return -1;
   
     //if only node in tree
    if(node->left == NULL && node->right == NULL) return 0;
    
    //search tree for longest node
    else {
	int left_height = tree_height(node->left);
	int right_height = tree_height(node->right);
	if(left_height > right_height) return (left_height +1);
	else return (right_height +1);
    }
}

// returns the total number of nodes
int BinarySearchTree::node_count() {
	return node_count(root);
}

int BinarySearchTree::node_count(Node *node) {
    //No nodes in tree
    if (node == NULL) return 0;

    //walks through tree, adds one for current node
    else return (node_count(node->left) + node_count(node->right) + 1);
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() {
	return count_total(root);
}

int BinarySearchTree::count_total(Node *node) {
    //if no nodes in tree
    if (node == NULL) return 0;

    //walks through tree adds data times the # times data appears in tree
    return (count_total(node->left) + count_total(node->right) 
		+ node->data * node->count);
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() {
	printPretty(root, 1, 0, std::cout);
}

Node *BinarySearchTree::find_parent(Node *node,Node *child) {
	if (node==NULL) return NULL;

	// if either the left or right is equal to the child,
	// we have found the parent
	if (node->left==child || node->right == child) {
		return node;
	}

	// Use the binary search tree invariant to walk the tree
	if (child->data > node->data) {
		return find_parent(node->right,child);
	}
	else {
		return find_parent(node->left,child);
	}
}
