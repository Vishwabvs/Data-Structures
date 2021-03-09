#include<iostream>
#include<stack>
#include<climits>
using namespace std;
void nextGreater(int* arr, int n)
{
    stack<int> s;
    stack<int> result;
    result.push(-1);
    s.push(arr[n - 1]);
    int res;
    for(int i = n - 2; i >= 0; i--)
    {
        while(!s.empty() && s.top() <= arr[i])
            s.pop();
        res = s.empty() ? -1 : s.top();
        result.push(res);
        s.push(arr[i]);
    }
    while(!result.empty())
    {
        cout<<result.top()<<" ";
        result.pop();
    }
    cout<<endl; 
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    nextGreater(arr, n);
    return 0;
}