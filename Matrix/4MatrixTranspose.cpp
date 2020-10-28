//Given a matrix, print transpose of it

//Solution 1: Using Array of pointers
#include<iostream>
using namespace std;
void transpose(int *arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
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
    transpose(arr,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

//Solution 2: Using Vector of Vectors
#include<iostream>
#include<vector>
using namespace std;
void transpose(vector<vector<int>> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr;
    int d;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            cin>>d;
            temp.push_back(d);
        }
        arr.push_back(temp);
    }
    transpose(arr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}