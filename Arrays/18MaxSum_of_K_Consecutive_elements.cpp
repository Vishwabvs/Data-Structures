//Given an array of size n, find the maximum Sum of K Consecutive elements
#include<iostream>
using namespace std;
int maxSum(int arr[], int n, int k)
{
	//O(n^2) approach
	int sum;
	int res = 0;
	for(int i=0;i<n-k+1;i++)
	{
		sum = 0;
		for(int j=0;j<k;j++)
		{
			sum+=arr[i+j];
		}
		res = max(res, sum);
	}
	return res;
}
int maxSum_efficient(int arr[], int n, int k)
{
	//O(n) approach
	int sum=0, index;
	int res = arr[0];
	for(int i=0;i<k;i++)
	{
		sum+=arr[i];
	}
	for(int i=k;i<n;i++)
	{
		sum = sum - arr[i-k] + arr[i];
		res = max(res, sum);
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
	int k;
	cin>>k;
	cout<<maxSum(arr, n, k)<<endl;
	return 0;
}
