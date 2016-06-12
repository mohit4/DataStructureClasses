#include "queueClass.cpp"

int main()
{
    Queue Q;
    Q.enqueue(11);
    Q.enqueue(21);
    Q.enqueue(31);
    int d = Q.dequeue();
    printQueue(Q);
    return 0;
}
