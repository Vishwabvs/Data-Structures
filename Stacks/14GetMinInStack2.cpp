//O(1) time and O(1) space
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
class MyStack
{
    int min;
    int *arr;
    int top;
    int capacity;
    public:
    MyStack(int size)
    {
        min = INT_MAX;
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
        if(top == -1)
        {
            min = data;
        }
        else if(data <= min)
        {
            arr[++top] = (2*data) - min;
            min = data;
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
        if(arr[top] <= min)
        {
            int retVal = min;
            min = (2*min) - arr[top];
            top--;
            return retVal;
        }
        return arr[top--];
    }
    int getMin()
    {
        return min;
    }
    int peek()
    {
        if(top == -1)
        {
            cout<<"Stack is Empty... No elements inside!!"<<endl;
            return -1;
        }

        int t = arr[top];
        return (t<=min) ? min : t;
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
    MyStack s(100);
    s.push(5);
    s.push(10);
    s.push(20);
    s.push(2);
    s.push(6);
    s.push(4);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    s.push(2);
    cout<<s.pop()<<endl;
    s.push(1);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl; 
    return 0;

}