#include<iostream>
using namespace std;
class MyStack
{
    int *arr;
    int top;
    int capacity;
    public:
    MyStack(int size)
    {
        top = -1;
        arr = new int[size];
        capacity = size;
    }
    void push(int data)
    {
        if(top == capacity)
        {
            cout<<"Cant Insert!!...Stack Full"<<endl;
            return;
        }
        arr[++top] = data;
    }
    int pop()
    {
        if(top == -1)
        {
            cout<<"Stack is Empty... Can't pop!!"<<endl;
            return -1;
        }
        return arr[top--];
    }
    int peek()
    {
        if(top == -1)
        {
            cout<<"Stack is Empty... No elements inside!!"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        return false;
    }
    int size()
    {
        return top+1;
    }
};
int main()
{
    MyStack s(10);
    s.push(5);
    s.push(15);
    s.push(25);
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    s.push(35);
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}