/*
  Preorder Traversal is a way to traverse each node of the tree like
  ROOT LEFT RIGHT
  For example : if the tree is 
        10
     5      40
  1    7        50
  
  then, the inorder traversal of the above tree is
  10, 5, 1, 7, 40, 50
*/

// Code

#include<stdio.h>
#include<stdlib.h>

//Structure for Node of Binary Search Tree
struct bst 
{
	struct bst *left;
	int data;
	struct bst *right;	
	int flag;
};

//Structure of Stack
struct stack
{
	struct bst *arr[10];
	int tos;
};

void push(struct stack *p,struct bst *x)
{
	if(p->tos==4)
	{
		printf("Stack overflow.");
		return;
	}
	p->tos++;
	p->arr[p->tos]=x;
}

struct bst * pop(struct stack *p)
{
	struct bst *x;
	if(p->tos==-1)
	{
		printf("Stack Underflow");
		return NULL;
	}
	else
	{
		x=p->arr[p->tos];
		p->tos--;
		return x;	
	}
}

//Method for Preorder traversing
void preorder(struct bst *p)
{
	struct stack s;
	s.tos=-1;
	if(p==NULL)
	{
		printf("Tree Empty.");
		return;
	}
	printf("Tree in preordered form is : ");
	push(&s,p);

	while(s.tos!=-1)				
	{
		p=pop(&s);
		while(p!=NULL)
		{
			if(p->right!=NULL)
			{
				push(&s,p->right);
			}
			printf("%d ",p->data);
			p=p->left;
		}
	}
}

/*
  Time Complexity - O(n)
  Space Complexity - O(h),
    where, h is the height of the tree.
*/
