//Given an array of size n, find the maximum possible subarray
#include<iostream>
#include<climits>
using namespace std;
int maxCrossingSubArray(int arr[], int low, int mid, int high)
{
	int lmax = INT_MIN;
	int rmax = INT_MIN;
	int sum = 0;
	for(int i=mid;i>=0;i--)
	{
		sum+=arr[i];
		lmax = max(lmax, sum);
	}
	sum = 0;
	for(int i=mid+1;i<=high;i++)
	{
		sum+=arr[i];
		rmax = max(rmax, sum);
	}
	return (lmax+rmax);
}
int maxFunc(int a, int b, int c)
{
	return max(max(a, b), c);
}
int maxSubArray(int *arr, int low, int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		int left = maxSubArray(arr, low, mid);
		int right = maxSubArray(arr, mid+1, high);
		int cross = maxCrossingSubArray(arr, low, mid, high);
		return maxFunc(left, right, cross);
	}
	return -1;
}
int maxSubArray_Kadane(int *arr, int n)
{
	int max_ending_here = arr[0];
	int curr_max = arr[0];
	for(int i=1;i<n;i++)
	{
		curr_max = max(arr[i] + curr_max, arr[i]);
		max_ending_here = max(curr_max, max_ending_here);	
	}
	return max_ending_here;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Maximum Sum Subarray is: "<<maxSubArray(arr, 0, n-1)<<endl;
	cout<<"Maximum Sum Subarray is: "<<maxSubArray_Kadane(arr, n)<<endl;
	return 0;
}
