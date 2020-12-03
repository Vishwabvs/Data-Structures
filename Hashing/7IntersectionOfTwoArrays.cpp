/*Given two arrays, find the intersection of the two arrays and also the array elements are not distinct.
Output should only contain distinct common elements.
Input: a[] = {10, 10, 10}
       b[] = {10, 10, 10}
Output: 1

Input: a[] = {10, 15, 20, 15, 30, 30, 5}
       b[] = {30, 5, 30, 80}
Output: 2*/

#include<iostream>
#include<unordered_set>
using namespace std;
int intersection(int* a, int *b, int m, int n)
{
    int count = 0;
    unordered_set<int> set;
    for(int i = 0; i < m; i++)
    {
        set.insert(a[i]);
    }
    for(int j = 0; j < n; j++)
    {
        if(set.find(b[j]) != set.end())
        {
            count++;
            set.erase(b[j]);
        }
    }
    return count;
}
int main()
{
    int m, n;
    cin>>m>>n;
    int a[m], b[n];
    for(int i = 0;i < m; i++)
        cin>>a[i];
    for(int j = 0; j < n; j++)
        cin>>b[j];
    cout<<intersection(a, b, m, n)<<endl;
    return 0;
}
