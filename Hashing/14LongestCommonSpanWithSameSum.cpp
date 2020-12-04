/*Given two binary arrays of size n, find the longest common span with same sum.
Input: arr1[] = {0, 1, 0, 0, 0, 0}
       arr2[] = {1, 0, 1, 0, 0, 1}
Output: 4
*/

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
int findLongestSpan(int* arr1, int *arr2, int n)
{
    int temp[n];
    for(int i = 0; i < n; i++)
        temp[i] = arr1[i] - arr2[i];
    return findSubarray(temp, n, 0);
}
int main()
{
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i = 0; i < n; i++)
        cin>>arr1[i];
    for(int i = 0; i < n; i++)
        cin>>arr2[i];
    cout<<findLongestSpan(arr1, arr2, n)<<endl;
    return 0;
}