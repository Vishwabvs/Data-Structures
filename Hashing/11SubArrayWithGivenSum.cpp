//Given an unsorted array of n elements, find if there is a subarray with given sum

#include<iostream>
#include<unordered_set>
using namespace std;
bool findSubarray(int *arr, int n, int sum)
{
    unordered_set<int> s;
    int curr = 0;
    for(int i = 0; i < n; i++)
    {
        if(curr == sum)
            return true;
        curr += arr[i];
        if(s.find(curr-sum) == s.end())
        {
            s.insert(curr);
        }
        else
        {
            return true;
        }   
    }
    return false;
}
int main()
{
    int n, sum;
    cin>>n>>sum;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<findSubarray(arr, n, sum)<<endl;
    return 0;
}