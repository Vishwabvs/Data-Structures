#include<iostream>
#include<stack>
using namespace std;
int findArea(int* arr, int n)
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
int findLargest(int arr[100][100], int m, int n)
{
    int res = findArea(arr[0], n);
    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j])
            {
                arr[i][j] += arr[i - 1][j];
            }
        }
        res = max(res, findArea(arr[i], n));
    }
    return res;
}
int main()
{
    int m, n;
    cin>>m>>n;
    int arr[100][100];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<findLargest(arr, m , n)<<endl;
}