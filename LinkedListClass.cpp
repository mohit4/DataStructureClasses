#include <iostream>
#include <assert.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *newnode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

class LinkedList
{
	Node *head,*tail;
public:
    int length;
	LinkedList(){head=tail=NULL;length=0;}
	~LinkedList()
	{
	    Node *temp = head;
        while(temp)
        {
            head=head->next;
            delete temp;
            temp=head;
        }
        length=0;
	}

    void insertBeg(int data)
    {
        Node *temp = newnode(data);
        if(!temp)
            return;
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
        length++;
    }

    void insertEnd(int data)
    {
        Node *temp = newnode(data);
        if(!temp)
            return;
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
        length++;
    }

    int deleteBeg()
    {
        if(head==NULL)
            assert("Error! Empty List.");
        Node *temp = head;
        int data = temp->data;

        head=head->next;
        length--;
        delete temp;
        return data;
    }

    int deleteEnd()
    {
        if(head==NULL)
            assert("Error! Empty List.");

        //need to search for preTail
        Node *preTail=head;
        while(preTail->next!=tail)
            preTail=preTail->next;

        //saving data for return
        int data=tail->data;
        //delete tail
        delete tail;
        length--;
        preTail->next=NULL;
        tail=preTail;
        return data;
    }

    //overloading the output operator
    friend ostream &operator<<(ostream &output,const LinkedList &obj)
    {
        Node *temp;
        temp = obj.head;
        while(temp)
        {
            output<<temp->data<<" ";
            temp=temp->next;
        }
        return output;
    }

};

int main()
{
    LinkedList mylist;
    //Give this code a try
    /*
    cout<<mylist.length<<" : "<<mylist<<"\n";
    mylist.insertBeg(0);
    cout<<mylist.length<<" : "<<mylist<<"\n";
    mylist.insertBeg(-1);
    cout<<mylist.length<<" : "<<mylist<<"\n";
    mylist.insertEnd(2);
    cout<<mylist.length<<" : "<<mylist<<"\n";
    mylist.insertEnd(3);
    cout<<mylist.length<<" : "<<mylist<<"\n";
    mylist.insertEnd(4);
    cout<<mylist.length<<" : "<<mylist<<"\n";
    mylist.deleteBeg();
    cout<<mylist.length<<" : "<<mylist<<"\n";
    mylist.deleteBeg();
    cout<<mylist.length<<" : "<<mylist<<"\n";
    mylist.deleteEnd();
    cout<<mylist.length<<" : "<<mylist<<"\n";
    mylist.insertBeg(1);
    cout<<mylist.length<<" : "<<mylist<<"\n";
    */
	return 0;
}
