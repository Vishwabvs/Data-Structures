//Given a set as an array, count the no of subsets that sum to the value K.
#include<iostream>
using namespace std;
int subsetSum(int arr[],int n, int sum)
{
	if(n==0)
	{
		if(sum == 0)
			return 1;
		else
			return 0;
	}
	return subsetSum(arr, n-1, sum)+subsetSum(arr, n-1, sum-arr[n-1]);
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
	cout<<subsetSum(arr, n, sum)<<endl;
}
