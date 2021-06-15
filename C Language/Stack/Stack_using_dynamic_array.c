/*
 Stack is a linear data structure which follows a particular order in which the operations are performed.
 The order may be LIFO(Last In First Out) or FILO(First In Last Out).

 We are performing following operations on the stack-
 1. Push - Inserting data into stack.
 2. Pop - Removing data from stack.
 3. Peek - Viewing top element of data.
 4. Traverse - Viewing elements of the stack.
*/
#include<stdlib.h>
#include<stdio.h>
struct arraystack
{
    int top;
    int capacity;
    int *ptr;
};

struct arraystack* createstack(int cap)
{
    struct arraystack *stackblock;
    stackblock=malloc(sizeof(struct arraystack));
    stackblock->capacity=cap;
    stackblock->top=-1;
    stackblock->ptr=malloc(sizeof(int)*stackblock->capacity);
    return(stackblock);
}


int isfull(struct arraystack *stack)
{
    if(stack->top == stack->capacity-1)
    {
        printf("Stack is full\n");
        return 1;
    }
    else
    {
        printf("Stack is not full\n");
        return 0;
    }
}


int isempty(struct arraystack *stack)
{
    if(stack->top == -1)
    {
        printf("Stack is empty\n");
        return 1;
    }
    else
    {
        printf("Stack is not empty\n");
        return 0;
    }
}


void push(struct arraystack *stack)
{
    if(isfull(stack))
        printf("\n");
    else
    {
        int data;
        printf("Enter the data to be pushed in the stack\n");
        scanf("%d",&data);
        stack->top++;
        stack->ptr[stack->top]=data;
    }
}


void pop(struct arraystack *stack)
{
    if(isempty(stack))
        printf("\n");
    else
    {
        int item;
        item=stack->ptr[stack->top];
        stack->top--;
        printf("Popped out %d from stack\n",item);
    }
}


void display(struct arraystack *stack)
{
    if(stack->top==-1)
        printf("Stack is empty\n");
    else
    {
        int temp=stack->top;
        while(temp != -1)
        {
            printf("%d ",stack->ptr[temp]);
            temp--;
        }
    }
}

void reverse(struct arraystack *stack)
{
    if(stack->top == -1)
        printf("Stack is empty\n");
    else
    {
        int temp=0;
        while(temp <= stack->top)
        {
            printf("%d ",stack->ptr[temp]);
            temp++;
        }
    }
}


void peek(struct arraystack *stack)
{
    if(stack->top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n",stack->ptr[stack->top]);
}

main()
{
    int cap;
    printf("Enter capacity of stack\n");
    scanf("%d",&cap);
    struct arraystack *stack;
    stack=createstack(cap);
    int choice;
    while(1)
    {
        printf("\nEnter Choice :\n");
        printf("\t1 To push\n");
        printf("\t2 To pop\n");
        printf("\t3 To check the stack is empty?\n");
        printf("\t4 To check the stacks is full?\n");
        printf("\t5 To view the stack\n");
        printf("\t6 To reverse the stack\n");
        printf("\t7 To peek / see the top element\n");
        printf("\t8 To exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                push(stack);
                break;
        case 2:
                pop(stack);
                break;
        case 3:
                isempty(stack);
                break;
        case 4:
                isfull(stack);
                break;
        case 5:
                display(stack);
                break;
        case 6:
                reverse(stack);
                break;
        case 7:
                peek(stack);
                break;
        case 8:
                exit(1);
                break;
        default:
            printf("Incorrect Choice\n");
        }
    }
}
