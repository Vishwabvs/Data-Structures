//Given an array of size n, find out whether there is a subarray of size k and with given sum
#include<iostream>
using namespace std;
int findSubarray(int arr[], int n, int sum, int k)
{
	int curr_sum = 0;
	for(int i=0;i<k;i++)
	{
		curr_sum += arr[i];
	}
	if(curr_sum == sum)
		return true;
	for(int i=k;i<n;i++)
	{
		curr_sum = curr_sum-arr[i-k]+arr[i];
		if(curr_sum == sum)
			return true;
	}
	return false;
}
int main()
{
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int sum;
	cin>>sum;
	cout<<findSubarray(arr, n, sum,k)<<endl;
	return 0;
}
