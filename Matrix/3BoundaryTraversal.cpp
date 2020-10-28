//Given a 2D matrix, print its boundary traversal
//https://www.geeksforgeeks.org/boundary-elements-matrix/

//Solution:
#include<iostream>
using namespace std;
void boundaryTraversal(int *arr[], int m, int n)
{
    if(m == 1)
    {
        for(int j=0;j<n;j++)
            cout<<arr[0][j]<<" ";
        return;
    }
    if(n == 1)
    {
        for(int i=0;i<m;i++)
            cout<<arr[i][0]<<" ";
        return;
    }
    for(int j=0;j<n;j++)
    {
        cout<<arr[0][j]<<" ";
    }
    for(int i=1;i<m;i++)
    {
        cout<<arr[i][n-1]<<" ";
    }
    for(int j=n-2;j>=0;j--)
    {
        cout<<arr[m-1][j]<<" ";
    }
    for(int i=m-2;i>=1;i--)
    {
        cout<<arr[i][0]<<" ";
    }
}
int main()
{
    int m, n;
    cin>>m>>n;
    int *arr[m];
    for(int i=0;i<m;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    boundaryTraversal(arr, m, n);
    return 0;
}