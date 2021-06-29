/*
	Stack is a linear data structure which works on the FIFO
	(First In First Out) principe, which means that the element which
	is inserted at last will be popped out(delted) first.\
	
	Stack have basic two methods known as
	1. Push - to insert the elemets in the stack.
	2. Pop - to remove the element from the stack.
	
	We can say that one end of stack is closed and all the operations
	are done from the other end.
	
	Basic structure of stack may resembel : 			
*/

			|		 	  |
			|     10      |
			|_____________|
			|     10      |
			|_____________|
			|     10      |
			|_____________|
			
/*
	From the above figure, we can see that the push, pop and other operations
	can only be performed from one end.
*/


// Code implementation for dynamic stack.
#include<bits/stdc++.h>
using namespace std;

// Structure of Stack
class Stack{
	int data;
	Stack *next;
	
	public:
		//Constructors
		Stack(){}
		
		Stack(int data){
			this->data = data;
			this->next = NULL;
		}
		// Basic methods
		Stack* push(Stack*, int);
		Stack* pop(Stack*);
};

// Driver Code
int main(){
	Stack st;
	Stack *tos = NULL;
	tos = st.push(tos, 10);
	tos = st.push(tos, 20);
	tos = st.push(tos, 5);
	tos = st.pop(tos);
}

// Push method to insert element in the stack.
Stack* Stack::push(Stack *tos, int data){
	
	// Creating a new node.
	Stack *node = new Stack(data);
	
	// Checking whether the space is allocated or not.
	if(node == NULL){
		cout<<"\nStack Overflow";
		return NULL;
	}
	
	// Link the new node to top of stack.
	node->next = tos;
	
	// Assign tos with new node.
	tos = node;
	return tos;
	
}

// Method to delete (or pop out) element from the stack.
Stack* Stack::pop(Stack *tos){
	
	// Check if stack if empty.
	if(tos == NULL){
		cout<<"Stack Underflow";
		return NULL;
	}
	
	// Store data of tos to some variable
	int data = tos->data;
	
	// Decrement tos to the previous stored element
	tos = tos->next;

	cout<<"Popped element is : "<<data;
	return tos;
}
