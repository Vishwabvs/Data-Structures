//Given an array of size n, and multiple queries of following types on the array, how to efficiently perform those queries.
//Query1: getSum(0, 2) --> gets the sum of elements from index o to 2
//Query2: getSum(1, 3) --> gets the sum of elements from index 1 to 3
//We have to do these query operations in O(1) time
#include<iostream>
using namespace std;
void prefixSum(int arr[], int n)
{
	int temp[n];
	temp[0] = arr[0];
	for(int i=1;i<n;i++)
		temp[i] = arr[i]+temp[i-1];
	
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int a, b;
		cin>>a>>b;
		cout<<"PrefixSum is: "<<temp[b]-temp[a]+arr[a]<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	prefixSum(arr, n);
	return 0;
}
