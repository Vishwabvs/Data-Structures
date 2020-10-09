//Given an array of size n, find out the maximum sum circular subarray
#include<iostream>
using namespace std;
int maxCircularSubarray(int arr[], int n)
{	
	//method 1
	// find normal subarray sum and then find minimum subarray sum and subtract it from the arraysum
	int total = 0;
	for(int i=0;i<n;i++)
		total += arr[i];
	int res = arr[0];
	int sum = arr[0];
	for(int i=1;i<n;i++)
	{
		sum = max(sum+arr[i], arr[i]);
		res = max(res, sum);
	}
	if(res<0)
		return res;
	sum = arr[0];
	int minimum = 0;
	for(int i=1;i<n;i++)
	{
		sum = min(sum+arr[i], arr[i]);
		minimum = min(minimum, sum);
	}
	return max(res, total-minimum);
}
int kadane(int arr[], int n)
{
    	int sum = arr[0];
    	int res = arr[0];
    	for(int i=1;i<n;i++)
    	{
       		sum = max(sum+arr[i], arr[i]);
        	res = max(res, sum);
    	}
    	return res;
}
int maxCircularSubarray(int arr[], int n)
{
	//method 2
	//find the normal subarray sum and then invert the elements and find the max sub array using kadane algorithm and then add it to the array sum
    	int max_normal = kadane(arr, n);
    	if(max_normal<0)
        	return max_normal;
    	int arraySum = 0;
    	for(int i=0;i<n;i++)
    	{
       		arraySum+=arr[i];
        	arr[i] *= -1;
    	}
    	return max(max_normal, arraySum+kadane(arr, n));
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<maxCircularSubarray(arr, n)<<endl;
	return 0;
}
