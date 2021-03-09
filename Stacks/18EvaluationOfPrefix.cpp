#include<iostream>
#include<stack>
using namespace std;
string prefixEval(string s)
{
    stack<string> stack;
    string result;
    for(int i = s.length() - 1; i>=0; i--)
    {
        if(s[i]>='a' && s[i] <= 'z')
        {
            string temp(1, s[i]);
            stack.push(temp);
            //cout<<stack.top()<<endl;
        }
        else
        {
            string a = stack.top();
            stack.pop();
            string b = stack.top();
            stack.pop();
            stack.push(a + s[i] + b);
        }
    }
    return stack.top();
}
int main()
{
    string s;
    cin>>s;
    cout<<prefixEval(s)<<endl;
    return 0;
}