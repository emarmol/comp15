#include "BSTree.h"

int main() {
	

    BST t;
    
    
	t.unbalancedInsert(54);
	t.unbalancedInsert(22);
	t.unbalancedInsert(17);
	t.unbalancedInsert(41);
	t.unbalancedInsert(36);
	t.unbalancedInsert(30);
	t.unbalancedInsert(74);
	t.unbalancedInsert(76);
	t.unbalancedInsert(26);
	t.unbalancedInsert(27);
	t.unbalancedInsert(45);
	t.unbalancedInsert(82);
	
	cout << endl;
	cout << "Ricky to the rescue:" << endl;
	cout << "printing inorder: ";
	t.inOrder();
	cout << endl;
	cout<< "Answer:           17 22 26 27 30 36 41 45 54 74 76 82";
	cout << endl;
	cout << endl;
	//cout << "printing postorder: ";
	//t.postOrder();
	//cout << endl;
	//cout <<"Answer:             17 27 26 30 36 45 41 22 82 76 74 54  ";
	//cout << endl;
	
	//cout << endl;
	//cout << endl;
	cout << "Stacey saves the day" << endl;
	cout << "printing preorder: ";
	t.preOrder();
    cout << endl;
	cout <<"Answer:            54 22 17 41 36 30 26 27 45 74 76 82";
	cout << endl;
	cout << endl;
	cout << "Quiet down, Quinn's in Town" << endl;
	cout << "printing levelorder: ";
	t.levelOrder();
	cout << endl;

	cout <<"Answer:              54 22 74 17 41 76 36 45 82 30 26 27";
	cout << endl;
	
	
	return 0;
}
