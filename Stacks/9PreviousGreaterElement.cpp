#include<iostream>
#include<stack>
#include<climits>
using namespace std;
void previousGreater(int* arr, int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout<<-1<<" ";
    int res;
    for(int i = 1; i < n; i++)
    {
        while(!s.empty() && s.top() <= arr[i])
            s.pop();
        res = s.empty() ? -1 : s.top();
        cout<<res<<" ";
        s.push(arr[i]);
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
    previousGreater(arr, n);
    return 0;
}