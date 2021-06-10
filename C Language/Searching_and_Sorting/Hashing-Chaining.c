#include<stdlib.h>
#include<stdio.h>

int size=10;                                             //hash table size

struct node
{
    int info;
    struct node *link;
};
struct node *hashtable[1000];

void addnode()
{
    int data,i,value;
    struct node *newnode,*temp;
    newnode = (struct node*) malloc (sizeof(struct node));

    printf("\nEnter number to be inserted : ");
    scanf("%d",&newnode->info);
    newnode -> link = NULL;

    value = newnode -> info;
    data = value % size;

    if(hashtable[data] == NULL)                        //if no node is present there at the index
        hashtable[data] = newnode;
    else
    {
        for(temp = hashtable[data] ; temp->link != NULL ; temp=temp->link)
            temp->link = newnode;
    }
}

int searchnode(int search)
{
    int data;
    struct node *temp;

    data = search % size;

    for(temp = hashtable[data] ; temp != NULL ; temp = temp->link)
    {
        if(search == temp->info)
            return data;
    }
    return -1;
}


int deletenode(int search)
{
    int data , i;
    struct node *newnode , *temp;
    data = search % size;

    if(search == hashtable[data]->info)
    {
        newnode = hashtable[data];
        hashtable[data] = hashtable[data]->link;
        free(newnode);
        return ;
    }

    for(newnode = hashtable[data] ; newnode->link != NULL ; newnode=newnode->link)
    {
        temp = newnode->link;
        if(search == temp->info)
        {
            newnode->link = temp->link;
            free(temp);
            break;
        }
    }

}


void printList(struct node *hashtable1)
{
    struct node *temp;

    for(temp = hashtable1 ; temp != NULL ; temp = temp->link)
        printf("[ %d ]",temp->info);
}


void printHashTable()
{
    int i;
    for(i = 0 ; i < size ; i++)
    {
        printf("\nHashTable [%d] : ",i);
        printList(hashtable[i]);
    }
}


int main()
{
    int i,choice,search,flag;

    for(i=0 ; i < size ; i++)
    {
        hashtable[i] = NULL;
    }

    while(1)
    {
        printf("\n\t1  To add keys into hash table.\n");
        printf("\t2  To search a key.\n");
        printf("\t3  To delete a key.\n");
        printf("\t4  To print HashTable.\n");
        printf("\t5  To exit.\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                addnode();
                break;

            case 2:

                printf("\nEnter key you want to search : ");
                scanf("%d",&search);

                flag = searchnode(search);

                if(flag == -1)
                    printf("\nKey not found\n");
                else
                {
                    printf("\nKey found : ");
                    printf("HashTable [ %d ] \n",flag);
                    printList(hashtable[flag]);
                }
                break;

            case 3:

                printf("\nEnter key you want to delete : ");
                scanf("%d",&search);

                flag = searchnode(search);

                if(flag == -1)
                    printf("\nKey not found\n");
                else
                {
                    deletenode(search);
                }
                break;

            case 4:

                printHashTable();
                break;

            case 5:

                exit(0);
                break;

            default:
                printf("\nInvalid Choice...\n");

        }
    }
    return 0;
}
