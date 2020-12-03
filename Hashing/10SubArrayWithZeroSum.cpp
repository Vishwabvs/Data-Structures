//Given an unsorted array of n elements, find if there is a subarray with zero sum

#include<iostream>
#include<unordered_set>
using namespace std;
bool findSubarray(int *arr, int n)
{
    unordered_set<int> s;
    s.insert(0);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(s.find(sum) == s.end())
        {
            s.insert(sum);
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
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<findSubarray(arr, n)<<endl;
    return 0;
}