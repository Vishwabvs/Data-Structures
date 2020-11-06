//Given a 2D matrix which are row-wise and column-wise sorted, search a given element and print its position if found
//https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

//Solution
#include<iostream>
using namespace std;
void search(int *arr[], int m, int n, int x)
{
    //O(n^2) approach
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j] == x)
            {
                cout<<"Found at ("<<i<<", "<<j<<")"<<endl;
                return;
            }
        }
    }
    cout<<"Not Found!"<<endl;
}
void search_efficient(int *arr[], int m, int n, int x)
{
    //O(R+C) approach
    int i=0, j= n-1;
    while(i<m && j>=0)
    {
        if(arr[i][j]==x)
        {
            cout<<"Found at ("<<i<<", "<<j<<")"<<endl;
            return;
        }
        else if(arr[i][j]>x)
            j--;
        else
            i++;
    }
    cout<<"Not Found!"<<endl;
}
int main()
{
    int m, n, x;
    cin>>m>>n;
    int *arr[m];
    for(int i=0;i<m;i++)
        arr[i] = new int[n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    cin>>x;
    search_efficient(arr, m, n, x);
}