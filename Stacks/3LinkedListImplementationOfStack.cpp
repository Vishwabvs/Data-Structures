#include<iostream>
#include<climits>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class MyStack
{
    Node* head;
    int capacity;
    public:
    MyStack()
    {
        capacity = 0;
        head = NULL;
    }
    void push(int data)
    {
        Node* newNode = new Node(data);
        if(!head)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        capacity++;
    }
    int pop()
    {
        if(head == NULL)
        {
            cout<<"No elements in Stack... Cant pop!!"<<endl;
            return INT_MAX;
        }
        Node* ptr = head;
        int temp = ptr->data;
        head = head->next;
        delete ptr;
        capacity--;
        return temp;        
    }
    int peek()
    {
        if(head == NULL)
        {
            cout<<"No elements in Stack... Cant pop!!"<<endl;
            return INT_MAX;
        }
        return head->data;
    }
    int size()
    {
        return capacity;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
};
int main()
{
    MyStack s;
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