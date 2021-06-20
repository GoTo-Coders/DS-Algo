/*
	The code provided below implements the construction of binary tree from
	postorder and inorder traversals.
	 Poxtorder Traversal - In this traversing method, we follow [ LEFT CHILD, RIGHT CHILD, ROOT] methadology.
	 Inorder Traversal - In this traversing method, we follow [ LEFT CHILD, ROOT, RIGHT CHILD] methadology.
	 
	The concept for constructing the tree is :
		The postorder traversal provides the root node at last after the subtree nodes, while 
		in inorder traversal, the left side of the data in array are the data of nodes of left subtree
		and that to the right are the data of nodes of right subtree.
		So, getting the data from the postorder we add it to the tree then,
		we search for it in the inorder array
		we repeat the process knowing that the left side is the left subtree
		and right side is the right subtree.
		We traverse from right to left in postorder array accessing the root node first.
		
	For example:
		Postorder traversal: 12, 8, 5, 14, 25, 20, 10
		Inorder traversal: 12, 5, 8, 10, 14, 20, 24
		Tree constructed from given data will be:
		
			        10
			      /    \
			     5	    20
			   /  \    /  \
			 12   8  14   24   

*/



#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *left, *right;
		
		Node(int data){
			this->data = data;
			this->left = this->right = NULL;
		}
};

Node *createBinary_from_inorder_postorder(int[], int[], int, int);
int search(int[], int, int, int);
void printPostorder(Node*);

int main(){
	int inorder[] = {2,5,7,10,15,20,25};
	int postorder[] = {2,7,5,15,25,20,10};
	int length = sizeof(postorder)/sizeof(postorder[0]);
	Node *root = createBinary_from_inorder_postorder(inorder, postorder, 0, length-1);
	
	cout<<"\nPostorder traversal of created binary tree is : ";
	printPostorder(root);
}

Node *createBinary_from_inorder_postorder(int inorder[], int postorder[], int start, int end)
{
	static int postIndex = end;
	
	if(start>end){
		return NULL;
	}	
	
	Node *newNode = new Node(postorder[postIndex--]);
	
	if(start == end){
		return newNode;
	}
	
	int inIndex = search(inorder, start, end, newNode->data);
	
	newNode->right = createBinary_from_inorder_postorder(inorder, postorder, inIndex+1, end);
	newNode->left = createBinary_from_inorder_postorder(inorder, postorder, start, inIndex-1);
	
	return newNode;
}

int search(int inorder[], int start, int end, int data){
	for(int i=start; i<=end; i++){
		if(inorder[i] == data)
			return i;
	}
}

void printPostorder(Node *root){
	if(root!=NULL){
		printPostorder(root->left);
		printPostorder(root->right);
		cout<<root->data<<" ";
	}
}
