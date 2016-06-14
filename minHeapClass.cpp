#include<iostream>
using namespace std;

class minHeap
{
    int *heap;  //the dynamically allocated heap array
    int size;   //size of heap
    int heap_size;  //current size
public:
    //constructor
    minHeap(int maxcap):size(maxcap){heap = new int[maxcap]; heap_size=0;}
    ~minHeap(){delete [] heap;}
    //heapify
    void minHeapify(int);
    //parent
    int parent(int i){return (i-1)/2;}
    //left child
    int left(int i){return 2*i+1;}
    //right child
    int right(int i){return 2*i+2;}

    //to extract min element from the heap
    int extractMin();
    //to return min element from the heap
    int getMin();
    //to decrease a key at index i to newVal
    void decreaseKey(int i,int newVal);
    //delete a key stored at i
    void deleteKey(int i);
    //insert new key
    void insertKey(int newKey);
    //friend function to show
    friend void show(minHeap &m)
    {
        for(int i=0;i<m.heap_size;i++)
            cout<<m.heap[i]<<" ";
        cout<<endl;
    }
};
inline void minHeap::insertKey(int newKey)
{
    if(size==heap_size)
        return;
    int i=heap_size;
    heap_size++;
    heap[i]=newKey;
    //adjust
    while(i!=0 && heap[parent(i)]>heap[i])
    {
        swap(heap[i],heap[parent(i)]);
        i=parent(i);
    }
}
inline void minHeap::deleteKey(int i)
{
    decreaseKey(i,INT_MIN);
    extractMin();
}
inline void minHeap::decreaseKey(int i,int newVal)
{
    heap[i]=newVal;
    while(i!=0 && heap[parent(i)]>heap[i])
    {
        swap(heap[i],heap[parent(i)]);
        i=parent(i);
    }
}
inline int minHeap::getMin()
{
    if(heap_size==0)
        return INT_MAX;
    return heap[0];
}
inline int minHeap::extractMin()
{
    if(heap_size==0)
        return INT_MAX;
    else if(heap_size==1)
    {
        int d=heap[0];
        heap_size--;
        return d;
    }
    int d=heap[0];
    heap[0]=heap[heap_size-1];
    heap_size--;
    minHeapify(0);
    return d;
}
inline void minHeap::minHeapify(int i)
{
    int smallest = i;
    int l=2*i+1,r=2*i+2;
    if(l<heap_size && heap[l]<heap[smallest])
        smallest=l;
    if(r<heap_size && heap[r]<heap[smallest])
        smallest=r;
    if(smallest!=i)
    {
        swap(heap[smallest],heap[i]);
        minHeapify(smallest);
    }
}

int main()
{
    minHeap H(10);
    H.insertKey(100);
    H.insertKey(8);
    H.insertKey(20);
    H.insertKey(16);
    H.insertKey(10);
    H.insertKey(70);
    H.insertKey(50);
    show(H);
    return 0;
}
