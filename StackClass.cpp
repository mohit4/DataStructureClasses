#include<iostream>
#include<assert.h>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};
Node<T> *newnode(T data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
class Stack
{
    Node *head;
public:
    Stack(){head=NULL;}
    ~Stack()
    {
        //destroy the complete stack
        if(head)
        {
            Node *temp = NULL;
            while(head)
            {
                temp=head;
                head=head->next;
                delete temp;
            }
        }
    }
    //for debugging purposes
    friend printStack(Stack &obj)
    {
        cout<<"\nStack : ";
        Node *it = obj.head;
        while(it)
        {
            cout<<it->data<<" ";
            it=it->next;
        }
        cout<<endl;
    }
    //to show the top element
    int top();
    //to push an element inside the stack
    void push(int);
    //to remove an element from top
    int pop();
    //to check if the stack is empty
    bool isEmpty();
};
inline int Stack::top()
{
    if(!head)
        assert("Error! Stack empty!");
    return head->data;
}
inline void Stack::push(int d)
{
    Node *temp = newnode(d);
    temp->next = head;
    head = temp;
}
inline int Stack::pop()
{
    if(!head)
        assert("Error! Stack empty!");
    Node *temp = head;
    head=head->next;
    int d = temp->data;
    delete temp;
    return d;
}
inline bool Stack::isEmpty()
{
    return (head==NULL);
}
