/*
	The code provided below implements the construction of binary tree from
	preorder and inorder traversals.
	 Preorder Traversal - In this traversing method, we follow [ ROOT, LEFT CHILD, RIGHT CHILD] methadology.
	 Inorder Traversal - In this traversing method, we follow [ LEFT CHILD, ROOT, RIGHT CHILD] methadology.
	 
	The concept for constructing the tree is :
		The preorder traversal provides the root node first followed by the subtree nodes, while 
		in inorder traversal, the left side of the data in array are the data of nodes of left subtree
		and that to the right are the data of nodes of right subtree.
		So, getting the data from the preorder we add it to the tree then,
		we search for it in the inorder array
		we repeat the process knowing that the left side is the left subtree
		and right side is the right subtree.
		
	For example:
		Preorder traversal: 10, 5, 12, 8, 20, 14, 24
		Inorder traversal: 12, 5, 8, 10, 14, 20, 24
		Tree constructed from given data will be:
		
					 10
				   /   \
				 5		20
			   /  \    /  \
			 12   8  14   24 	

*/

// Code - Implementation of constructing a binary tree from given inorder and preorder traversals.

#include<bits/stdc++.h>
using namespace std;

// Class Node providing the structure and constructor for the node of binary tree.
class Node{
	public:
		int data;
		Node *left;
		Node *right;
		
		Node(int data){
			this->data = data;
			this->left = this->right = NULL;
		}
};

Node *create_binary_from_inorder_preorder(int[], int[], int, int);
int search(int[], int, int, int);
void printPreorder(Node *root);

int main(){
	
	int preorder[] = {1,2,4,8,9,10,11,5,3,6,7};
	int inorder[] = {8,4,10,9,11,2,5,1,6,3,7};
	int size = sizeof(preorder)/sizeof(preorder[0]);
	Node *root = NULL;
	root = create_binary_from_inorder_preorder(preorder, inorder, 0, size-1);
	
// For verification, print the inorder traversal of above created binary tree.
	cout<<"\nPreorder of created tree is : ";
	printPreorder(root);

	return 0;
}

// Method for creating the binary tree from given inorder and preorder traversals.
Node *create_binary_from_inorder_preorder(int preorder[], int inorder[], int start, int end)
{
// preIndex for traversing the preorder array in each call.
	static int preIndex = 0;
	
	if(start>end){
		return NULL;
	}

// Creating a new node with the preIndex value from preorder array.	
	Node *newNode = new Node(preorder[preIndex++]);
	
// If the node is leaf node (do not have any child nodes), then return the created node.
	if(start == end){
		cout<<"\n Node Inserted : "<<newNode->data;
		return newNode;
	}
		
// If the node further have children, then we search the index of the node data in inorder array.
	int inIndex = search(inorder, start, end, newNode->data);
	
// After finding the index in inorder, we will recursively call create_binary_from_inorder_preorder()
// method to create the left and right subtrees of this node.

// For left subtree, we provide the array from start upto the inIndex-1 of searched data in inoder.
	newNode->left = create_binary_from_inorder_preorder(preorder, inorder, start, inIndex-1);
	
// Similarly, for right subtree, we provide the array from inIndex+1 upto end index.
	newNode->right = create_binary_from_inorder_preorder(preorder, inorder, inIndex+1, end);
	
	cout<<"\n Node Inserted : "<<newNode->data;
	
	return newNode;
		
	
}

// Method to find the index of the element in the inorder array.
int search(int inorder[], int start, int end, int data){
	for(int i=start; i<=end; i++){
		if(inorder[i] == data)
			return i;
	}
}

// Method to print the preorder traversal of constructed binary tree.
void printPreorder(Node *root){
	if(root!=NULL){
		cout<<root->data<<" ";
		printPreorder(root->left);
		printPreorder(root->right);		
	}
}

/*
 Worst Case time complexity = O(n^2)
*/

