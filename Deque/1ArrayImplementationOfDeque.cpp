#include<iostream>
#include<climits>
using namespace std;
class Deque
{
    int* arr;
    int capacity;
    int size;
    int front;
    public:
    Deque(int x)
    {
        capacity = x;
        arr = new int[x];
        front = 0;
        size = 0;
    }
    int getFront()
    {
        if(size == 0)
            return -1;
        return front;
    }
    int getRear()
    {
        if(size == 0)
            return -1;
        return (front + size - 1) % capacity;
    }
    int getSize()
    {
        return size;
    }
    void insertFront(int x)
    {
        if(size == capacity - 1)
        {
            cout<<"Deque Full!!"<<endl;
            return;
        }
        front = (front - 1 + capacity) % capacity;  
        arr[front] = x; 
        size++;     
    }
    void insertRear(int x)
    {
        if(size == capacity - 1)
        {
            cout<<"Deque Full !!"<<endl;
            return;
        }
        int rear = (getRear() + 1) % capacity;
        arr[rear] = x;
        size++;
    }
    int deleteFront()
    {
        if(size == 0)
        {
            cout<<"Deque is empty!!"<<endl;
            return INT_MAX;
        }
        int temp = arr[front];
        front = (front + 1) % capacity;
        size--;
        return temp;
    }
    int deleteRear()
    {
        if(size == 0)
        {
            cout<<"Deque is empty!!"<<endl;
            return INT_MAX;
        }
        int temp = arr[getRear()];
        int rear = (getRear() - 1 + capacity) % capacity;
        size--;
        return temp;
    }
};
int main()
{
    Deque dq(10);
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertFront(30);
    dq.insertRear(50);
    cout<<dq.deleteFront()<<endl;
    cout<<dq.deleteRear()<<endl;
    return 0;
}