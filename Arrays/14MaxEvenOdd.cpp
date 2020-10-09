//Given an array of size n, find the maximum length of even odd subarray
#include<iostream>
using namespace std;
int maxEvenOdd(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		arr[i] = arr[i]%2;
		//cout<<arr[i]<<" ";
	}
	cout<<endl;
	int res = 0;
	int count = 1;
	
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]==arr[i+1])
		{
			//cout<<"hi"<<endl;
			res = max(res, count);
			count = 1;
		}
		else
		{
			count++;
			res = max(res, count);
		}
	}
	
	return res;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<maxEvenOdd(arr, n)<<endl;
	return 0;
}
