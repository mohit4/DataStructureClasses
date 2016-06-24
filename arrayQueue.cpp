#include<iostream>
using namespace std;

//implemented a circular Queue
class Queue
{
    //data structure used
    int *arr;
    //maximum size of memory alloted
    int size;
    //index for front and rear
    int in,out;
public:
    Queue(int n=10):size(n)
    {
        arr = new int[n];
        in=out=-1;
    }
    ~Queue()
    {
        delete [] arr;
    }
    bool isFull(){ return ((in+1)%size)==out; }
    bool isEmpty(){ return in==out; }
    bool enQueue(int a)
    {
        if(isFull())
            return false;
        if(out==-1)
            out++;
        in=(in+1)%size;
        arr[in]=a;
        return true;
    }
    int deQueue()
    {
        if(isEmpty())
            return INT_MAX;
        int t=arr[out];
        out=(out+1)%size;
        return t;
    }
    int front(){return arr[out];}
    int rear(){return arr[in];}
};

int main()
{
    Queue Q;
    Q.enQueue(10);
    Q.enQueue(20);
    Q.enQueue(30);
    Q.deQueue();
    cout<<Q.front()<<endl<<Q.rear()<<endl;
    return 0;
}
