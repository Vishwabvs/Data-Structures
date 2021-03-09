#include<iostream>
#include<climits>
#include<stack>
using namespace std;
int findArea(int* arr, int n)
{
    if(n == 0)
        return 0;
    int res = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int curr = arr[i];
        for(int j = i - 1; j >= 0; j--)
        {
            if(arr[j] >= arr[i])
                curr += arr[i];
            else
                break;
        }
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] >= arr[i])
                curr += arr[i];
            else
                break;
        }
        res = max(res, curr);
    }
    return res;
}
int findArea2(int* arr, int n)
{
    int res = 0;
    int ps[n];
    int ns[n];
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
        {
            //cout<<s.top();
            s.pop();
        }
        //cout<<endl;
        ps[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    for(int i = 0; i < n; i++)
    {
        cout<<ps[i]<<" ";
    }
    cout<<endl;
    while(!s.empty())
        s.pop();
    ns[n - 1] = -1;
    for(int i = n - 1; i >= 0; i--)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        ns[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    for(int i = 0; i < n; i++)
    {
        cout<<ns[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        int curr = arr[i];
        curr += arr[i]*(i - ps[i] - 1);
        curr += arr[i]*(ns[i] - i - 1);
        res = max(res, curr);
    }
    return res;
}
int findArea3(int* arr, int n)
{
    int res = 0;
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
        {
            int idx = s.top();
            s.pop();
            int curr = arr[idx] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }
    while(!s.empty())
    {
        int idx = s.top();
        s.pop();
        int curr = arr[idx] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<findArea3(arr, n);
    return 0;
}