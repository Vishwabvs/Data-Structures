#include<iostream>
#include<stack>
using namespace std;
void stockSpan(int* arr, int n)
{
    //Naive Approach
    for(int i = 0; i < n; i++)
    {
        int span = 0;
        for(int j = i; j >=0 && arr[j] <= arr[i]; j--)
        {
            span++;
        }
        cout<<span<<" ";
    }
    cout<<endl;
}
void stockSpan2(int* arr, int n)
{
    //O(n) time and O(n) space
    stack<int> s;
    s.push(0);
    cout<<1<<" ";
    int span;
    for(int i = 1; i < n; i++)
    {
        while(!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        span = s.empty() ? i+1 : i - s.top();
        cout<<span<<" ";
        s.push(i);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    stockSpan2(arr, n);
    return 0;
}