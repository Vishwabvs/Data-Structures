//https://www.geeksforgeeks.org/array-rotation/
//Time: O(n)
//Space: O(d)

//Using Temp array
#include<iostream>
using namespace std;
int main()
{
    int n = 10,k = 3,q = 0;
    int temp[n];
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};   //Expected O/p:{8 10 12 14 16 18 20 2 4 6}
    k = k%n;
    for(int i=0;i<k;i++)
        temp[i] = arr[i];
    for(int i=k;i<n;i++)
        arr[i-k] = arr[i];
    for(int i=n-k;i<n;i++)
        arr[i] = temp[q++];
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
