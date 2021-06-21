/*
	Binary Search Tree (BST) is a special case of binary tree which follows the rule that:
		1. ALl the nodes(data) to the left of the parent node should be less than the parent itself.
		2. All the nodes(data) to the right of the parent node should be greater than the parent node data.
		
	For example: 
					10
			      /    \
			     5	    20
			   /  \    /  \
			 2    8  15   24   
		
		Note that, each node to the left of parent is smaller and that to the right is greater than the parent node.
		
		Insertion in BST: We are follwing recursive approach to insert the data in the tree.
						We call the method again and again until we reach to the leaf node or at the correct position.
						
		Deletion in BST: While deleting a node in BST, three cases arise
		   Node to be deleted have
			1. 0 child: In this case, we delete the node and assign NULL to the parent pointing to this node.
			2. 1 child: We link the child of this node to the parent of the node and then delete it.
			3. 2 children: In this case, we find either the inorder successor or inorder predecessor of the node, copies
						the data of inorder successor in the node to be deleted, and finally deletes the inorder successor.
						
		Traversing BST: We generally follow inorder approach in BST, as it provides sorted data.
		
	
*/

//Implementation of insertion, deletion and display methods for binary search tree.
#include<bits/stdc++.h>
using namespace std;

// Structure of node of a binary search tree.
class BST{
	int data;
	BST *left, *right;
	
	public:	
		BST(int data){
			this->data = data;
			this->left = this->right = NULL;
		}
		
		BST(){
		}
		
		// Method to display data of root after every deletion.
		int displayRootData(BST *root){
			return root->data;	
		}
		
		// Method to insert node in the BST.
		BST* insert(BST *root, int data){
			
		// Base condition, reaching the desired position.
			if(root == NULL){
				return (new BST(data));
			}
			
		// Traversing further according to the conditions followed.
			if(root->data > data)
				root->left = insert(root->left, data);
			else
				root->right = insert(root->right, data);
				
			return root;
		}
		
		// Method to find the inorder successor, in case the node to
		// be deleted have 2 chldren.
		BST* findSuccessor(BST *root){
			BST *current = root;
			while(current && current->left != NULL){
				current = current->left;
			}
			return current;
		}
		
		// Method to delete the node of the BST.
		BST* delBST(BST* root, int data){
			
		// Base condition, if node is not present in the tree.
			if(root == NULL){
				cout<<"\nNode is not present in the tree.";
				return root;
			}
			
			// Traversing the BST to reach the desired node.
			if(data > root->data)
				root->right = delBST(root->right, data);
			
			else if(data < root->data)
				root->left = delBST(root->left, data);
				
			// Reaching the desired node data = root->data.	
			else{
				
			// If the node have 0 child.
				if(root->left == NULL && root->right == NULL){
					delete root;
					return NULL;
				}
				
			// If node have 1 child, checking which side does it contain child.
				else if(root->left == NULL){
					BST *temp = root->right;
					delete root;
					return temp;
				}
				
				else if(root->right == NULL){
					BST *temp = root->left;
					delete root;
					return temp;
				}
				
			// If node have 2 children
				else{
				
				// First, we find the inorder successor of the node.
					BST *temp = findSuccessor(root->right);
				
				// Copying the successor data in the desired node data.	
					root->data = temp->data;
					
				// Again Calling the method to delete the inorder successor.
					root->right = delBST(root->right, temp->data);
				}
			}
			return root;
		}
		
	// Traversing and displaying the data of nodes of BST in inorder fashion.
		void display(BST *root){
			if(root!=NULL){
				display(root->left);
				cout<<root->data<<" ";
				display(root->right);
			}
		}
};


//User driven main() method.
int main(){
	BST *root = NULL;
	
	int choice, data;
	
	BST b;
	
	while(1){
		cout<<"\n1. Add BST \n2. Delete Node \n3. Display Tree \n4. Exit \nChoose operation to perform : ";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"\nInsert data to add : ";cin>>data;
				root = b.insert(root, data);
				break;
			case 2:
				cout<<"\nInsert data to delete from tree : ";cin>>data;
				b.delBST(root, data);
				cout<<"\nRoot of the tree is : "<<b.displayRootData(root);
				break;
			case 3:
				b.display(root);
				break;
			case 4:
				exit(0);
			default:
				cout<<"\nPlease enter a valid choice!";
		}
	}
	
	return 0;
}




