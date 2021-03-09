#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
int helper(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else 
        return -1;
}
string infix_prefix(string s)
{
    stack<char> stack;
    string result;
    for(int i = s.length() - 1; i >=0; i--)
    {
        if(s[i] == ')')
        {
            stack.push(s[i]);
        }
        else if(s[i] == '(')
        {
            while(!s.empty() && stack.top() != ')')
            {
                result += stack.top();
                stack.pop();
            }
            if(!s.empty())
                stack.pop();
        }
        else if(s[i] >='a' && s[i]<='z')
        {
            result += s[i];
        }
        else
        {
            while(!stack.empty() && helper(stack.top()) > helper(s[i]))
            {
                result += stack.top();
                stack.pop();
            }
            stack.push(s[i]);
        }
    }
    while(!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    string s;
    cin>>s;
    cout<<infix_prefix(s)<<endl;
    return 0;
}