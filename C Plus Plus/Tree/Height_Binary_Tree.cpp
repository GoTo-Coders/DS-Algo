/*
Height of a Binary tree is the total depth i.e. the maximum number of nodes from root to any leaf node.
		For example : if binary tree is
			        10
			      /    \
			     5	    20
			   /  \    /  \
			 12   8  14   24  
			       \
				   34
				   
			then the height of the tree will be 4 as from root (10) to 
			leaf nodes, their are correspnding number of nodes
			12 - 3 nodes
			34 - 4 nodes
			14 - 3 nodes
			24 - 3 nodes
			
			So, we choose the maximum number(4) as the maximum height/depth of tree.
*/

//Implementation 

#include<bits/stdc++.h>
using namespace std;

// Basic structure of node in binary tree.
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
    int height(Node*);

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
        cout<<preorder[i]<<" ";
    }

    cout<<"Height of the tree : "<<node.height(root);

    return 0;
}

// Method for finding the height of the tree.
int Node::height(Node *root){
	
	//If tree do not contain any nodes
    if(root == NULL){
        return 0;
    }
    
    // Initially assign 0 to the height of left and right subtree of individual nodes
    int leftdepth = 0, rightdepth = 0;

	// Recursively find the left and right subtree heights.
    leftdepth = height(root->left);
    rightdepth = height(root->right);
	
	// Return either left subtree hieght or right subtree hieght 
	// whichever is greater.
    return (leftdepth<rightdepth) ? rightdepth+1 : leftdepth+1;
}

/*
	For height method using recursion
	Time Complexity: O(n)
	Space Complexity: O(n) 
*/
