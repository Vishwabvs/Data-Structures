//Given an array of size n, find out whether there is a subarraywith given sum. Note that the window size is not fixed and may vary.
//Also the array contains only non-negative integers
#include<iostream>
using namespace std;
int findSubarray(int arr[], int n, int sum)
{
	int curr_sum=0, k=0, i;
	for(i=0;i<n;i++)
	{
		curr_sum += arr[i];
		if(curr_sum == sum)
			return true;
		if(curr_sum > sum)
			break;
	}
	for(int j = i;j<n;j++)
	{
		while(curr_sum>sum)
		{
			curr_sum = curr_sum - arr[j-i];	
		}
		if(curr_sum == sum)
			return true;
		curr_sum = curr_sum + arr[j];
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int sum;
	cin>>sum;
	cout<<findSubarray(arr, n, sum)<<endl;
	return 0;
}
