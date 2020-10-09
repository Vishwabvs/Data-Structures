#include<iostream>
using namespace std;
int majorityElement(int arr[], int n)
{
	int majority = arr[0];
	int count = 1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=majority)
		{
			if(count>1)
			{
				count--;
			}
			else
			{
				majority = arr[i];
				count = 1;
			}
		}
		else
		{
			count++;
		}
	}
	count = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==majority)
			count++;
	}
	if(count>n/2)
		return majority;
	else
		return -1;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<majorityElement(arr, n)<<endl;
	return 0;
}
