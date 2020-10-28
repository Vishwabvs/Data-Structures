#include<iostream>
using namespace std;
void spiralTraversal(int *arr[], int m, int n)
{
    int r_start = 0;
    int r_end = m-1;
    int c_start = 0;
    int c_end = n-1;

    for(int i=r_start;i<r_end;i++)
    {
        
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
    spiralTraversal(arr, m, n);
    return 0;
}  