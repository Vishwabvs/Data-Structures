//Given an array of size n, find the only odd occuring element in the array
#include<iostream>
using namespace std;
int oddOccuring(int arr[], int n)
{
	int total = 0;
	for(int i=0;i<n;i++)
		total += arr[i];
	for(int i=0;i<n;i++)
	{
		if((total - arr[i])%2 == 0)
			return arr[i];
	}
	return -1;
}
int oddOccuring2(int arr[], int n)
{
	//using xor 
	int x = arr[0];
	for(int i=1;i<n;i++)
		x = x^arr[i];
	return x;	
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<oddOccuring2(arr, n)<<endl;
	return 0;
}
