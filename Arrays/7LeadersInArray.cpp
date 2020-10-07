//Given an array of size n, find all the leaders in it. An element is called the leader of an array if there is no element greater than it on the right side.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printLeaders(int arr[], int n)
{
	vector<int> res;
	int curr = arr[n-1];
	cout<<curr<<" ";
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]>curr)
		{
			curr = arr[i];
			cout<<curr<<" ";
		}
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	printLeaders(arr, n);
	return 0;
}
