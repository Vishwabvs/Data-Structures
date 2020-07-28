//https://www.geeksforgeeks.org/array-rotation/
//Time:O(n*d)
//Space: O(1)


//Rotate by one method
#include<iostream>
using namespace std;
int main()
{
    int n = 10,k = 3,q = 0;
    int temp[n];
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};   //Expected O/p:{8 10 12 14 16 18 20 2 4 6}
    k = k%n;
    while(q<k)
    {
        int temp = arr[0];
        for(int i=0;i<n-1;i++)
        {
            arr[i] = arr[i+1];
        }
        arr[n-1] = temp;
        q++;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
