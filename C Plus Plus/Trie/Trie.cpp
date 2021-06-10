#include <bits/stdc++.h>
#include <string>
using namespace std;

struct Trie
{
    Trie *child[26];
    int we;              //End of Word
};

Trie* createNode()
{
    struct Trie *newnode = new Trie;

    newnode->we = 0;

    for(int i=0 ; i<26 ; i++)
        newnode->child[i] = NULL;

    return newnode;
}

void insertNode(struct Trie *root , string key)
{
    struct Trie *trie = root;

    for(int i=0 ; i<key.length() ; i++)
    {
        //getting the index of each character
        int index = key[i] - 'a';
        if(trie->child[index] == NULL)
            trie->child[index] = createNode();
        trie = trie->child[index];          //moving to its children for further storing
    }
    trie->we += 1;
}

bool searchNode(struct Trie *root , string key)
{
    struct Trie *trie = root;

    for(int i=0 ; i<key.length() ; i++)
    {
        int index = key[i] - 'a';

        if(!trie->child[index])                     //if((trie->child[index] == NULL) || (trie->child[index]->we == 0))
            return false;

        trie = trie->child[index];
    }
    return (trie != NULL && trie->we);              //return true;
}

bool deleteNode(struct Trie *root , string key)
{
    if(searchNode(root , key))
    {
        struct Trie *trie = root;
        for(int i=0 ; i<key.length() ; i++)
        {
            int index = key[i] - 'a';
            trie->child[index]->we -= 1;
            trie = trie->child[index];
        }
        return true;
    }
    return false;
}

void printWord(string str[] , int n)
{
    cout<<endl;
    for(int i=0 ; i<n ; i++)
        cout<<str[i];
}

void display(struct Trie *root , string wordArray[] , int pos)
{
   if(root == NULL)
      return;

   if(root->we)
      printWord(wordArray , pos);

   for(int i=0 ; i<26 ; i++)
   {
      if(root->child[i] != NULL)
      {
         wordArray[pos] = i+'a';
         display(root->child[i] , wordArray , pos+1);
      }
   }
}

int main()
{
    struct Trie *root = createNode();
    string keys[15];
    int choice;

    while(1)
    {
        cout<<"\n1.Insert \t 2.Search \t 3.Delete \t 4.Display \t 5.EXIT"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            {
                int n;
                cout<<"Enter number of strings : ";
                cin>>n;
                cout<<"Enter the strings :\n";
                for(int i=0 ; i<n ; i++)
                {
                    cin>>keys[i];
                    insertNode(root , keys[i]);
                }

                break;
            }

        case 2:
            {
                string key;
                cout<<"Enter the string : ";
                cin>>key;

                bool result = searchNode(root , key);

                if(result)
                    cout<<"String is found"<<endl;
                else
                    cout<<"String is not found"<<endl;

                break;
            }

        case 3:
            {
                string key;
                cout<<"Enter the string : ";
                cin>>key;

                bool result = deleteNode(root , key);

                if(result)
                    cout<<"String is deleted"<<endl;
                else
                    cout<<"String is not found"<<endl;

                break;
            }


        case 4:
            {
                //There is some issue in it and working on it
                cout<<"Contents of Trie : "<<endl;
                display(root , keys , 0);
                break;
            }

        case 5:
            exit(0);
            break;

        default:
            cout<<"\nINVALID CHOICE\n";
        }
    }
    return 0;
}
