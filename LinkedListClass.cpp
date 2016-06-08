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
    LinkedList(){head=tail=NULL;
        length=0;
    }
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
    void insertBeg(int);
    void insertEnd(int);
    int deleteBeg();
    int deleteEnd();
    int indexOf(int);
    void deleteAt(int);
    void insertAt(int,int);
    int getFront()
    {
        if(head==NULL)
            return -1;
        return head->data;
    }
    int getEnd()
    {
        if(head==NULL)
            return -1;
        return tail->data;
    }
    int &operator[](int i)
    {
        if(i>=length)
            assert("Index out of range!");
        Node *temp = head;
        int counter=0;
        while(counter!=i)
        {
            temp=temp->next;
            counter++;
        }
        return temp->data;
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
inline void LinkedList::insertBeg(int data)
{
    Node *temp = newnode(data);
    if(!temp)
    return;
    if(head==NULL)
    head=tail=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
    length++;
}
inline void LinkedList::insertEnd(int data)
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
inline int LinkedList::deleteBeg()
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
inline int LinkedList::deleteEnd()
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
inline int LinkedList::indexOf(int data)
{
    Node *temp = head;
    int counter=0;
    while(temp && temp->data!=data)
    {
        temp=temp->next;
        counter++;
    }
    if(!temp)
        return -1;
    return counter;
}
inline void LinkedList::deleteAt(int i)
{
    Node *temp=head,*pre=NULL;
    int counter=0;
    if(!head)
        assert("Empty list!");
    if(i>=length)
        assert("Index out of range!");
    if(i==0)
        this->deleteBeg();
    else if(i==length-1)
        this->deleteEnd();
    else
    {
        while(counter<i)
        {
            pre=temp;
            temp=temp->next;
            counter++;
        }
        pre->next=temp->next;
        delete temp;
        length--;
    }
}
inline void LinkedList::insertAt(int i,int data)
{
    Node *temp=head,*pre=NULL;
    int counter=0;
    if(!head)
        assert("Empty list!");
    if(i>length)
        assert("Index out of range!");
    if(i==0)
        this->insertBeg(data);
    else if(i==length)
        this->insertEnd(data);
    else
    {
        while(counter<i)
        {
            pre=temp;
            temp=temp->next;
            counter++;
        }
        Node *NewNode = newnode(data);
        NewNode->next=temp;
        pre->next=NewNode;
        length++;
    }
}
