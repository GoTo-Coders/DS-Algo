/*
	Linked Lists are linear data structure. A circular linked list is formed 
	by connecting nodes from one to other in a linear fashion i.e. one node is 
	connected to second and it is connected to other and so on, adding a feature
	that in a circular linked list the last node is connected to the first node 
	for better traversal.
	Each node of a linked list contains two elements
		1. Data - the data is stored in this part
		2. Next (or link) - the address of the node which is to be connected
				to this node is stored in *next.
				
	Unlike arrays, nodes are not stored in a sequential manner in the memory, instead
	they are stored randomly in the memory and we access the node using the address of that memory.
	
	The outflow of the link list can be understood using the below figure.
	
		 -->|data|next|---->|data|next|---->|data|next|---
		|	                                              |
		--------------------------------------------------
						
*/


// Linked List Implementaion


#include<bits/stdc++.h>
using namespace std;

// The structure of node of linked list as described above
// and its corresponding methods.
class Node{
		int data;
		Node *next;
	public:
		
		// Constructors for Node
		Node(){}
		
		Node(int data){
			this->data = data;
			this->next = this;
		}
		
		Node(Node *root,int data){
			this->data = data;
			this->next = root;
		}
		
		// Method to insert node into the linked list.
		Node *insert(Node *root, int data){
			Node *temp = root;
			
			// If the node to be inserted is the first node.
			if(root == NULL){
				return (new Node(data));
			}
			
			// If it is not first not, we'll traverse to the last node
			// and then join the new node there.
			do{
				temp = temp->next;
			}
			while(temp->next != root);
			
			temp->next = new Node(root, data);

			return root;	
		}

		// Method to delete a node from the linked list.
		Node *delNode(Node *root, int data){
			
			// Condition for list is empty
			if(root == NULL){
				cout<<"\nList is empty";
				return root;
			}
			
			Node *temp = root;
			Node *prev = temp;
			
			// If the data is present at the first node.
			if(root->data == data){
				
				// If the list contains only one node.
				if(root->next == root){
					free(root);
					cout<<"\nNode Deleted";
					return NULL;
				}
				
				// If the list contains multiple nodes.
				else{
					root = root->next;
					free(temp);
					temp = root;
					while(temp->next != prev){
						temp = temp->next;
					}
					temp->next = root;
					cout<<"\nNode Deleted";
					return root;
				}
			}
			
			// If data is present at some other location in the list.
			// We traverse to the respective node.
			while(temp->data != data && temp->next!=root){
				prev = temp;
				temp = temp->next;
			}
			
			// If data is found in the list.
			if(temp != root){
				prev->next = temp->next;
				free(temp);
				cout<<"\nNode Deleted";
			}
			
			// If data is not found in the list.
			else{
				
				cout<<"\nData not found in the list";
			}
			return root;
		}
		
		// Display method to show the data of the linked list.
		void display(Node *root){
			Node *temp = root;
			if(root == NULL){
				cout<<"\nList is empty";
			}
			else{
				cout<<"\nList elements are : ";
				do{
					cout<<temp->data<<" ";
					temp = temp->next;
				}
				while(temp!=root);
			}
		}
};

// User driven code main() method for implementing linked list.
int main(){
	
	// Start pointer to store the address of first node.
	Node *root = NULL;
	
	Node obj;
	int choice, data;
	
	// The loop will continue running until the user itself terminates the program.
	do{
		cout<<"\n1.Insert Node \n2.Display List \n3.Delete Node \n4.Exit \nEnter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter number to insert in the list : ";cin>>data;
				root = obj.insert(root, data);
				break;
			case 2:
				obj.display(root);
				break;
			case 3:
				cout<<"\nEnter number to delete from list :";cin>>data;
				root = obj.delNode(root, data);
				break;
			case 4:
				exit(0);
			default:
				cout<<"\nPlease enter a valid choice!";	
		}
	}while(1);
}

