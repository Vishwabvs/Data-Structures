#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverse(queue<int>& q)
{
    /*stack<int> aux;
    while(!q.empty())
    {
        aux.push(q.front());
        q.pop();
    }
    while(!aux.empty())
    {
        q.push(aux.top());
        aux.pop();
    }*/
    if(q.empty())
    {
        return;
    }
    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(5);
    q.push(15);
    q.push(20);
    reverse(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}