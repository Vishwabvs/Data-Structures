#include<iostream>
#include<stack>
using namespace std;
string postfixEval(string s)
{
    stack<string> stack;
    string result;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]>='a' && s[i] <= 'z')
        {
            string temp(1, s[i]);
            stack.push(temp);
            cout<<stack.top()<<endl;
        }
        else
        {
            string a = stack.top();
            stack.pop();
            string b = stack.top();
            stack.pop();
            stack.push(b + s[i] + a);
        }
    }
    return stack.top();
}
int main()
{
    string s;
    cin>>s;
    cout<<postfixEval(s)<<endl;
    return 0;
}