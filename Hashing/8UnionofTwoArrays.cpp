//Given two arrays, find the no of elements in union of two arrays
//Union must contain only the distinct elements

#include<iostream>
#include<unordered_set>
using namespace std;
int unionArrays(int* a, int *b, int m, int n)
{
    unordered_set<int> set;
    for(int i = 0; i < m; i++)
    {
        set.insert(a[i]);
    }
    for(int j = 0; j < n; j++)
    {
        set.insert(b[j]);
    }
    return set.size();
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
    cout<<unionArrays(a, b, m, n)<<endl;
    return 0;
}
