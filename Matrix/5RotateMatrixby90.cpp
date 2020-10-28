//Given a 2D Matrix, rotate it by 90 degrees anti-clockwise and print it
//https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/

//Solution
#include<iostream>
#include<vector>
using namespace std;
void rotate90(int* arr[], int n)
{
    //Takes O(n^2) Time and O(n^2) aux space
    int temp[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[n-j-1][i] = arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            arr[i][j] = temp[i][j];
    }
}
void rotate90_efficient(int* arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n/2;i++)
        {
            swap(arr[i][j], arr[n-i-1][j]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int *arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    rotate90_efficient(arr, n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}