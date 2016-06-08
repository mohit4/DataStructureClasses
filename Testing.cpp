#include "LinkedListClass.cpp"

int main()
{
    LinkedList mylist;
    //Give this code a try
    /*
    cout<<mylist.length<<" : "<<mylist<<endl;
    mylist.insertBeg(0);
    cout<<mylist.length<<" : "<<mylist<<endl;
    mylist.insertBeg(-1);
    cout<<mylist.length<<" : "<<mylist<<endl;
    mylist.insertEnd(2);
    cout<<mylist.length<<" : "<<mylist<<endl;
    mylist.insertEnd(3);
    cout<<mylist.length<<" : "<<mylist<<endl;
    mylist.insertEnd(4);
    cout<<mylist.length<<" : "<<mylist<<endl;
    mylist.deleteBeg();
    cout<<mylist.length<<" : "<<mylist<<endl;
    mylist.deleteBeg();
    cout<<mylist.length<<" : "<<mylist<<endl;
    mylist.deleteEnd();
    cout<<mylist.length<<" : "<<mylist<<endl;
    mylist.insertBeg(1);
    cout<<mylist.length<<" : "<<mylist<<endl;
    */
    mylist.insertEnd(12);
    mylist.insertEnd(24);
    mylist.insertEnd(36);
    //cout<<"24 at position "<<mylist.indexOf(24)+1;
    //cout<<"\n"<<mylist[0];
    cout<<mylist<<endl;
    /*
    mylist[0]=-12;
    cout<<mylist<<endl<<mylist.getEnd()<<endl;
    mylist.deleteAt(mylist.indexOf(36));
    cout<<mylist.getEnd();
    */
    mylist.insertAt(0,6);
    mylist.insertAt(mylist.length-1,10);
    cout<<mylist;
    return 0;
}

