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
class Queue
{
    Node *head,*tail;
public:
    Queue(){head=tail=NULL;}
    ~Queue()
    {
        Node *it = head;
        while(it)
        {
            head=head->next;
            delete it;
            it=head;
        }
    }

    friend void printQueue(Queue &obj)
    {
        Node *it = obj.head;
        while(it!=NULL)
        {
            cout<<it->data<<" ";
            it=it->next;
        }
        cout<<endl;
    }

    void enqueue(int);
    int dequeue();
    int front();
    int rear();
    bool isEmpty();
};
bool Queue::isEmpty()
{
    return (head==NULL);
}
void Queue::enqueue(int data)
{
    Node *temp = newnode(data);
    if(head==NULL)
    {
        head=tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}
int Queue::dequeue()
{
    if(head==NULL)
        assert("Error! Empty Queue!");
    int d=head->data;
    Node *it=head;
    head=head->next;
    delete it;
    return d;
}
int Queue::front()
{
    if(head==NULL)
        assert("Error! Empty Queue!");
    return head->data;
}
int Queue::rear()
{
    if(head==NULL)
        assert("Error! Empty Queue!");
    return tail->data;
}
