//https://www.geeksforgeeks.org/c-program-cyclically-rotate-array-one/
//Given an array, cyclically rotate an array by one.



//Solution
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
        cin>>arr[i];
	int temp = arr[n-1];
    for(int i=n-1;i>=0;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
	return 0;
}
