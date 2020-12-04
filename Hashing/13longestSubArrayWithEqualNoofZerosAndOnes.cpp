//Given a binary array of size n, find the length of longest subarray with equal no of zeros and ones in it

#include<iostream>
#include<unordered_map>
using namespace std;
int findSubarray(int *arr, int n, int sum)
{
    unordered_map<int, int> m;
    int curr = 0, res = 0, max1 = 0;
    for(int i = 0; i < n; i++)
    {
        curr += arr[i];
        if(curr == sum)
            res = i+1;
        if(m.find(curr) == m.end())
            m[curr] = i;
        if(m.find(curr - sum) != m.end())
            res = max(res, i - m[curr - sum]);
    }
    return res;
}
int findLongestSubarray(int *arr, int n)
{
    int res = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            arr[i] = -1;
    }
    return findSubarray(arr, n, 0);
}
int main()
{
    int n, sum;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<findLongestSubarray(arr, n)<<endl;
    return 0;
}