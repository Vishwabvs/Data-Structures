//https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
//Time: O(n)
//Space: O(1)

//Reversal algorithm
#include<iostream>
using namespace std;

void rverse(int *arr,int start,int end)
{
    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n;

        d = d%n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>d;

        rverse(arr,0,d-1);


        rverse(arr,d,n-1);


        rverse(arr,0,n-1);

        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
