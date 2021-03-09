#include<iostream>
#include<vector>
using namespace std;
class MyStack
{
    vector<int> v;
    public:
    MyStack()
    {}
    void push(int data)
    {
        v.push_back(data);
    }
    int pop()
    {
        int temp = v.back();
        v.pop_back();
        return temp;
    }
    int peek()
    {
        return v.back();
    }
    bool isEmpty()
    {
        return v.empty();
    }
    int size()
    {
        return v.size();
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