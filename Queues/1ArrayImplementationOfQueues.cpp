#include<iostream>
#include<climits>
using namespace std;
class Queue
{
    int *arr;
    int front, rear;
    int capacity;
    public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[size];
        front = rear = -1;
    }
    void enqueue(int x)
    {
        if(rear == capacity - 1)
        {
            cout<<"Queue Full"<<endl;
            return;
        }
        if(rear == -1)
        {
            front++;
        }
        rear++;
        arr[rear] = x;
    }
    int dequeue()
    {
        if(rear == -1)
        {
            cout<<"Queue empty"<<endl;
            return INT_MAX;
        }
        int temp = arr[front];
        int i = front;
        while(i != rear)
        {
            arr[i] = arr[i + 1];
            i++;
        }
        rear--;
        return temp;
    }
    int getFront()
    {
        return arr[front];
    }
    int getRear()
    {
        return arr[rear];
    }
    int size()
    {
        if(rear == -1)
            return 0;
        return rear - front + 1;
    }
    bool isFull()
    {
        return (rear == capacity - 1);
    }
    bool isEmpty()
    {
        return (rear == -1);
    }
};
int main()
{
    Queue q(100);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q.dequeue()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.size()<<endl;
    return 0;
}