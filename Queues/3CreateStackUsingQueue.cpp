#include<iostream>
#include<queue>
using namespace std;
struct Stack
{
    queue<int> q;
    queue<int> aux;
    Stack()
    {}
    int top()
    {
        if(q.empty())
            return -1;
        return q.front();
    }
    void push(int x)
    {
        /*aux.push(x);
        while(!q.empty())
        {
            aux.push(q.front());
            q.pop();
        }
        q = aux;
        while(!aux.empty())
            aux.pop();*/
        if(q.size() == 0)
        {
            q.push(x);
            return;
        }
        int temp = q.front();
        q.pop();
        push(x);
        q.push(temp);
    }
    int pop()
    {
        int temp = q.front();
        q.pop();
        return temp;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    return 0;
}