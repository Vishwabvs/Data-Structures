//Given an unsorted array of size n, find if there is a pair with given sum

#include<iostream>
#include<unordered_set>
using namespace std;
bool findPair(int *arr, int n, int sum)
{
    unordered_set<int> s;
    for(int i = 0; i < n; i++)
    {
        if(s.find(sum - arr[i])!=s.end())
            return true;
        s.insert(arr[i]);
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
    cout<<findPair(arr, n, sum)<<endl;
    return 0;
}