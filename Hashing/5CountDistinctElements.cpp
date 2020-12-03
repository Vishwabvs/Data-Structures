//Given an array of n elements, count no of distinct elements in the array

#include<iostream>
#include<unordered_set>
using namespace std;
int countDistinct(int* arr, int n)
{
    unordered_set<int> s;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    return s.size();
}   
int countDistinct_efficient(int* arr, int n)
{
    unordered_set<int> s(arr, arr+n);
    return s.size();
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<countDistinct_efficient(arr, n)<<endl;
    return 0;
}