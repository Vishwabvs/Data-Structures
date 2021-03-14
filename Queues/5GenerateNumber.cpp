#include<iostream>
#include<queue>
using namespace std;
void generate(int n)
{
    queue<string> q;
    q.push("5");
    q.push("6");
    for(int i = 0; i < n; i++)
    {
        string aux = q.front();
        cout<<aux<<" ";
        q.pop();
        q.push(aux + "5");
        q.push(aux + "6");
    }
}
int main()
{
    
    int n;
    cin>>n;
    generate(n);
    return 0;
}