/*
	Traversing a binary tree includes three ways : 
		1. Preorder Traversal
		2. Inorder Traversal
		3. Postorder Traversal
		
	1. Preorder Traversal - In this traversing method, we follow [ ROOT, LEFT CHILD, RIGHT CHILD] methadology.
		For example : if binary tree is
			        10
			      /    \
			     5	    20
			   /  \    /  \
			 12   8  14   24   
			 
			then the preorder traversal will be 
				10, 5, 12, 8, 20, 14, 24
			note that, it follows above discussed methadology.
			
	2. Inorder Traversal - In this traversing method, we follow [ LEFT CHILD, ROOT, RIGHT CHILD] methadology.
		For example : if binary tree is
			        10
			      /    \
			     5	    20
			   /  \    /  \
			 12   8  14   24    
			 
			then the preorder traversal will be 
				12, 5, 8, 10, 14, 20, 24
			note that, it follows above discussed methadology.
			
	3. Postorder Traversal - In this traversing method, we follow [ LEFT CHILD, RIGHT CHILD, ROOT] methadology.
		For example : if binary tree is
			        10
			      /    \
			     5	    20
			   /  \    /  \
			 12   8  14   24   
			 
			then the preorder traversal will be 
				12, 8, 5, 14, 24, 20, 10
			note that, it follows above discussed methadology.
			
	The implementation of the above three traversals follows recursive approach.
	On each call of the method we divide the tree into the sub-tree with passed argument node as the root.
	For example: 
		In the above tree, for the first call the root will be 10.
		On the second recursive call the root will be 5; 
		then 12 until we reach NULL and the call traces back providing the required output.
*/


#include <bits/stdc++.h>
using namespace std;

// Below sections includes construction of tree.
// ---Starts---

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

// ---Ends---


// Method for preorder traversal
void preorder(binaryTree *root)
{
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}	
}

// Method for inorder traversal
void inorder(binaryTree *root)
{
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

// Method for postorder traversal
void postorder(binaryTree *root)
{
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";

	}
}

int main()
{
// Creating the root pointer for the binary tree.
    binaryTree *root = NULL;

// Calling the create method and storing the address of the root node into root pointer declared above.    
    root = create();
    
    cout<<"\nTree created successfully : ";
    
// For preorder traversal. 
    cout<<"\nTree in preorder traversal is : ";
    preorder(root);
    
// For inorder traversal. 
    cout<<"\nTree in inorder traversal is : ";
    inorder(root);
    
// For postorder traversal. 
    cout<<"\nTree in postorder traversal is : ";
    postorder(root);
    
    return 0;
}

/*
	Time complexity of Preorder, Inorder ande Postorder traversal: O(n)
	Space Complexity: O(h), where 'h' is the height of the tree.
