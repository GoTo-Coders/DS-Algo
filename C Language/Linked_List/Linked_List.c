/*
	Linked Lists are linear data structure. A singly linked list is formed 
	by connecting nodes from one to other in a linear fashion i.e. one node is 
	connected to second and it is connected to other and so on.
	Each node of a linked list contains two elements
		1. Data - the data is stored in this part
		2. Next (or link) - the address of the node which is to be connected
				to this node is stored in *next.
				
	Unlike arrays, nodes are not stored in a sequential manner in the memory, instead
	they are stored randomly in the memory and we access the node using the address of that memory.
	
	The outflow of the link list can be understood using the below figure.
	
			|data|next|---->|data|next|----> |data|next|
						
*/


// Linked List Implementaion

#include<stdio.h>
#include<stdlib.h>

// The structure of node of linked list as described above.
struct node
{
  int data;
  struct node *next;
};

// Method to insert a new node in 
void append(struct node ** ,int );
void display(struct node *);
void del(struct node **,int);

// User driven code main() method for implementing linked list.
int main(void)
{
// Start pointer to store the address of first node.
	struct node *start=NULL;
  
	int n,m;
// The loop will continue running until the user itself terminates the program.
	do
	{
    	printf("\nEnter Choice \n1. Append \n2.Display \n3.Delete \n5.Quit            ");
    	scanf("%d",&n);
    	switch(n)
    	{
    	case 1:
			printf("\nEnter no. of your choice");
			scanf("%d",&m);
			append(&start,m);
			break;
	    case 2:
			display(start);
			break;
	    case 3:
			printf("\nEnter no. to delete from list");
			scanf("%d",&m);
			del(&start,m);
			break;	
    	case 4:
			exit(0);
	    default:
			 printf("\nplease enter a valid choice");
	    }
	} while(1);  
	
	return 0;
}	

// Method to insert node into the linked list.
void append(struct node **ps, int x)
{
	struct node *p, *temp;

// Creating a new node for insertion.
	p=(struct node *)malloc(sizeof(struct node));
	p->data = x;
	p->next = NULL;
	
// If the node to be inserted is the first node.
	if(*ps == NULL)
	{
    	*ps=p;
	}
	
// If it is not first not, we'll traverse to the last node
// and then join the new node there.
	else
	{
    	temp=*ps;
    	while(temp->next!=NULL)
    	{
    	  temp=temp->next;
    	}
    	temp->next=p;
	}
}

// Display method to show the data of the linked list.
void display(struct node *p)
{
	int count=1;
	if(p==NULL)
	{
    	printf("\nlist is empty");
	}
	else
	{
	  	printf("\nList is : ");
	    while(p !=NULL)
	    {
	      count++;
	      printf("%d ",p->data);
	      p=p->next;
	    }
	}
}

// Method to delete a node from the linked list.
void del(struct node **ps, int x)
{
	struct node *temp, *p;
	
// Condition for list is empty
	if(*ps==NULL)
	{
		printf("\nList is empty");
		return;
	}
	temp=*ps;
	
// If provided node is the first node of the list.
	if((*ps)->data==x)
	{
	    *ps=temp->next;
	    free(temp);
	    printf("\nNode Deleted ");
	    return;
	}
	
// In other conditions.
	while(temp!=NULL && temp->data!=x)
	{
	    p=temp;
	    temp=temp->next;
	}
	
// If the data provided is not present in the list.
	if(temp==NULL)
	{
    	printf("\nData is not availaible in the list ");
	}
	else
	{
    	p->next=temp->next;
    	free(temp);
    	printf("\nNode Deleted");
  	}
}


