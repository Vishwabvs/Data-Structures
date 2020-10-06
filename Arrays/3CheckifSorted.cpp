//Given an array, check whether if it is sorted
#include<iostream>
using namespace std;
bool checkSorted(int *arr, int n)
{
	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<checkSorted(arr, n)<<endl;
	return 0;
}
