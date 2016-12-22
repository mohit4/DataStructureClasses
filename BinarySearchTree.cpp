#include <iostream>
using namespace std;

struct tnode
{
    int data;
    tnode *next;
};

tnode *newnode(int d)
{
    tnode *temp = new tnode;
    temp->data = d;
    temp->next = NULL;
    return temp;
}

class BinarySearchTree
{
    tnode *root;
    int size;
public:
    //constructor
    BinarySearchTree()
    {
        size=0;
        root=NULL;
    }
    //insert operation
    bool insert(int d)
    {
        tnode *t = newnode(d);
        if(root==NULL)
            root=t;
        else
        {
            //we've to search for the correct location
            tnode *curr;
            while(true)
            {

            }
        }
    }
};
