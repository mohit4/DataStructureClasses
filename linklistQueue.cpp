#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newnode(int d)
{
    Node *t = new Node;
    t->data = d;
    t->next = NULL;
    return t;
}

class Queue
{
    Node *head,*tail;
    int length;
public:
    Queue(){length=0;head=tail=NULL;}
    ~Queue(){}
    bool isEmpty(){return (head==tail);}
    void enQueue(int a)
    {
        Node *t = newnode(a);
        if(head==NULL)
            head=tail=t;
        else
        {
            tail->next = t;
            tail = t;
        }
        length++;
    }
    int deQueue()
    {
        if(isEmpty())
            return INT_MAX;
        int d = head->data;
        Node *t = head;
        head=head->next;
        delete t;
        length--;
        return d;
    }
    int front(){return head->data;}
    int rear(){return tail->data;}
    int size(){return length;}
};

int main()
{
    Queue Q;
    Q.enQueue(10);
    Q.enQueue(20);
    Q.enQueue(30);
    Q.enQueue(40);
    Q.deQueue();
    cout<<Q.size()<<" "<<Q.front()<<" "<<Q.rear()<<" ";
    return 0;
}
