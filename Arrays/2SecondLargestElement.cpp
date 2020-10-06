//Given an array arr[], print the index of the second largest element. If all the elements are equal print -1
#include<iostream>
using namespace std;
int SecondLargest_Naive(int arr[], int n)
{
	int largest = arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>largest)
			largest = arr[i];
	}
	int second = -99999;
	int res = -1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=second && arr[i]<largest)
		{
			res = i;
			second = arr[i];
		}
	}
	return res;
}
int SecondLargest_Efficient(int arr[], int n)
{
	int largest = 0;
	int res = -1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[largest])
		{
			res = largest;
			largest = i;
		}
		else if(arr[i]<arr[largest])
		{
			if(res==-1 || arr[res]<arr[i])
			{
				res = i;
			}
		}
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<SecondLargest_Naive(arr, n)<<endl;
	cout<<SecondLargest_Efficient(arr, n)<<endl;
	return 0;
}
