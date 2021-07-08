/*
Preorder Traversal - In this traversing method, we follow [ ROOT, LEFT CHILD, RIGHT CHILD] methadology.
		For example : if binary tree is
			        10
			      /    \
			     5	    20
			   /  \    /  \
			 12   8  14   24   
			 
			then the preorder traversal will be 
				10, 5, 12, 8, 20, 14, 24
			note that, it follows above discussed methadology.
*/

#include<bits/stdc++.h>
using namespace std;

//Initial Template for C++

class Node
{
public:
    // The structure of each node of the binary tree.
    int data;
    Node *left;
    Node *right;

    //Default Constructor
    Node(){}

    //Constructor to initialize pointers with NULL
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }

    Node* create();
    vector<int> preOrder(Node *);

};

vector<int> Node::preOrder(Node *root)
{
    // Creating stack for storing the right child of node.
    stack<Node *> stack;

    // Final preorder result.
    vector<int> preorder;

    do
    {
        preorder.push_back(root->data);

        // If the child contains right child
        // push it into stack
        if (root->right != NULL)
        {
            stack.push(root->right);
        }

        // and traverse to the left child.
        root = root->left;

        // If root becomes null, then
        // pop out an element from the stack
        if (root == NULL && !stack.empty())
        {
            root = stack.top();
            stack.pop();
        }

    } while (!stack.empty() || root != NULL);

    return preorder;
}

Node* Node::create()
{
//Data to be added to the binary tree.
    int x; 
    
//Taking input from user
    cout << "\nEnter data (-1 for no node) : ";
    cin >> x;
    if (x == -1)
        return NULL;

//Creating a node for the inserted data.
	Node *newNode = new Node(x);
	
//Asking for left and right child of the node.
    cout << "\nFor left child of "<<x<<" : ";
    newNode->left = create();

    cout << "\nFor right child of "<<x <<" : " ;
	newNode->right = create();

    return newNode;
}

int main()
{
// Creating the root pointer for the binary tree.
    Node *root = NULL;

    Node node;

// Calling the create method and storing the address of the root node into root pointer declared above.    
    root = node.create();
    
    cout<<"\nTree created successfully : ";
    
// For preorder traversal. 
    cout<<"\nTree in preorder traversal is : ";
    vector<int> preorder =  node.preOrder(root);
    for(int i=0; i<preorder.size(); i++){
        cout<<preorder[i];
    }

    return 0;
}