//Given an array, we need to find the longest subsequence that has consecutive elements. These consecutive elements may appear in any order in the subsequence.
#include<iostream>
#include<unordered_set>
using namespace std;
int findConsecutiveSubSequence(int *arr, int n)
{
    unordered_set<int> s;
    for(int i = 0; i < n ; i++)
    {
        s.insert(arr[i]);
    }
    int curr = 1, res = 1;
    for(int i = 0 ; i < n; i++)
    {   
        if(s.find(arr[i] - 1) == s.end())
        {
            curr = 1;
            while(s.find(arr[i] + curr) != s.end())
            {
                curr++;
            }
            res = max(curr, res);
        } 
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
    cout<<findConsecutiveSubSequence(arr, n)<<endl;
    return 0;
}