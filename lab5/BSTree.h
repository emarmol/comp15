#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>


using namespace std;


struct BSTNode {
		int value;
		BSTNode* left;
		BSTNode* right;
};



class BST 

{

	public:
	
    	BST();
    
        void unbalancedInsert(int v);
        void inOrder();
        void preOrder();
        void postOrder();
        void levelOrder();

	
	
    private:
	
        BSTNode* root;
	
        BSTNode* unbalancedInsert(BSTNode* root, int v);
	
        void inOrder(BSTNode* root);
        void preOrder(BSTNode* root);
        void levelOrder(BSTNode* root);
        void postOrder(BSTNode* root);
};
	


