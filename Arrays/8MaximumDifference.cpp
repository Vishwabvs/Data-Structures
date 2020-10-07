//Given an array of size n, find the maximum difference. Maximum Difference problem is to find the maximum of arr[j] - arr[i] where j>i.
#include<iostream>
using namespace std;
int maxDifference(int arr[], int n)
{
	int max_diff = arr[1]-arr[0];
	int min_ele = arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]-min_ele >max_diff)
		{
			max_diff = arr[i]-min_ele;
		}
		if(min_ele>arr[i])
			min_ele = arr[i];
	}
	return max_diff;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<maxDifference(arr, n)<<endl;
	return 0;
}
