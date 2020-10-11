//Given an array of size n, find if it has an equilibrium point 
//Equilibrium Point is an element where sum of all elements before that element is equal to sum of all elements after it
#include<iostream>
using namespace std;
int getSum(int prefixSum[], int index)
{
	//cout<<index<<endl;
	if(index<0)
		return 0;
	return prefixSum[index];
}
bool equilibriumPoint(int arr[], int n)
{
	//O(n) extra space
	int prefixSum[n] = {0};
	prefixSum[0] = arr[0];
	for(int i=1;i<n;i++)
		prefixSum[i] = prefixSum[i-1]+arr[i];
	for(int i=0;i<n;i++)
	{
		int lsum = getSum(prefixSum, i-1);
		int rsum = prefixSum[n-1]-prefixSum[i];
		if(i==n-1)
			rsum = 0;
		//cout<<"LSum: "<<lsum<<" RSum: "<<rsum<<endl;
		if(lsum == rsum)
			return true;
	}
	return false;
}
bool equilibriumPoint_efficient(int arr[], int n)
{
	//O(1) extra space
	int arraySum = 0;
	for(int i=0;i<n;i++)
		arraySum += arr[i];
	int lsum = 0;
	for(int i=0;i<n;i++)
	{
		int rsum = arraySum - arr[i] - lsum;
		if(lsum == rsum)
			return true;
		lsum += arr[i];
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
	cout<<equilibriumPoint(arr, n)<<endl;
}
