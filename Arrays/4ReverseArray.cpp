//Given an array, reverse it and display
#include<iostream>
using namespace std;
void ReverseArray(int *arr, int start, int end)
{
	while(start<end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	ReverseArray(arr, 0, n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
