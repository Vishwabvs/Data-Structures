//Given an unsorted array of range[1,..,n+1], one element is missing. Find it

//Solution: This approach can be done in other ways also but here we are doing with bit manip
#include<iostream>
using namespace std;
int findMissing(int arr[], int n)
{
	int res = 0;
	for(int i=0;i<n;i++)
	{
		res = res^arr[i];
	}
	for(int i=1;i<=n+1;i++)
		res = res^i;
	return res;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<findMissing(arr, n)<<endl;
}
