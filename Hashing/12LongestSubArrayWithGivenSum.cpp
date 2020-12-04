//Given an unsorted array of n elements, find if there is a subarray with given sum and return the length of longest subarray with that given sum

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
int main()
{
    int n, sum;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>sum;
    cout<<findSubarray(arr, n, sum)<<endl;
    return 0;
}