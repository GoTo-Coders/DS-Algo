/*
	A binary tree is a tree data structure in which each node have 
	maximum of 2 nodes called left and right child of the respective node.
	
	A binary tree node contains following parts:
	1. Data
	2. Pointer to the left child node
	3. Pointer to the right child node.
	
	For example:
				10
		   5		 20
		12   8	 14     24
	is a binary tree in which 5 and 20 are the left and right child of the root node 10.
	While, (12, 8), (14, 24) are the left and right child nodes of 5 and 20 respectively.
	
	Note that, 12, 8, 14, 24 are the leaf nodes and thus does not have any child.
	They contain NULL in the left and right pointers.
	

*/

// Code implementation.
#include <bits/stdc++.h>
using namespace std;

struct binaryTree
{
public:
    // The structure of each node of the binary tree.
    int data;
    binaryTree *left;
    binaryTree *right;

    //Constructor to initialize pointers with NULL
    binaryTree(int x)
    {
    	data = x;
        left = right = NULL;
    }

};

//Recursion based create() method to implement binary tree.
binaryTree *create()
{
//Data to be added to the binary tree.
    int x; 
    
//Taking input from user
    cout << "\nEnter data (-1 for no node) : ";
    cin >> x;
    if (x == -1)
        return NULL;

//Creating a node for the inserted data.
	binaryTree *newNode = new binaryTree(x);
	
//Asking for left and right child of the node.
    cout << "\nFor left child of "<<x<<" : ";
    newNode->left = create();

    cout << "\nFor right child of "<<x <<" : " ;
	newNode->right = create();

    return newNode;
}

int main()
{
//Creating the root pointer for the binary tree.
    binaryTree *root = NULL;

//Calling the create method and storing the address of the root node into root pointer declared above.    
    root = create();
    
    cout<<"Tree created successfully : ";
    
    return 0;
}
