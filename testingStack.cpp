#include "StackClass.cpp"

int main()
{
    Stack mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.pop();
    printStack(mystack);
    return 0;
}
