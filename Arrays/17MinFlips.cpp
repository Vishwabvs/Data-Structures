//Given a binary array, we need to find the minimum of number of group flips to make all array elements same.  In a group flip, we can flip any set of consecutive 1s or 0s.
#include<iostream>
using namespace std;
void printOnes(int arr[], int n)
{
	int from = -1;
	for(int i=1;i<n;i++)
	{
		if(arr[i-1]==1&& from ==-1)
		{
			from = 1;
			cout<<"From "<<i-1<<" to ";
		}
		if(arr[i]!=arr[i-1] && arr[i] == 0)
		{
			cout<<i-1<<endl;
			from = -1;
		}
	}
	if(arr[n-1]==1)
	{
		if(from == -1)
		{
			cout<<"From "<<n-1<<" to "<<n-1<<endl;
		}
		else
		{
			cout<<n-1<<endl;
		}
	}
}
void printZeros(int arr[], int n)
{
	int from = -1;
	for(int i=1;i<n;i++)
	{
		if(arr[i-1]==0&& from ==-1)
		{
			from = 1;
			cout<<"From "<<i-1<<" to ";
		}
		if(arr[i]!=arr[i-1] && arr[i] == 1)
		{
			cout<<i-1<<endl;
			from = -1;
		}
	}
	if(arr[n-1]==0)
	{
		if(from == -1)
		{
			cout<<"From "<<n-1<<" to "<<n-1<<endl;
		}
		else
		{
			cout<<n-1<<endl;
		}
	}
}
void minFlips(int arr[], int n)
{
	//Requires two traversals of  the array(not efficient)
	int ones = 0;
	for(int i=1;i<n;i++)	
	{
		if((arr[i]==0&&arr[i-1]==1) || (i==n-1 && arr[i] == 1))
		{
			ones++;
		}
	}
	int zeros = 0;
	for(int i=1;i<n;i++)	
	{
		if((arr[i]==1&&arr[i-1]==0) || (i==n-1 && arr[i] == 0))
		{
			zeros++;
		}
	}
	if(zeros==n || ones == n)
	{
		return;
	}
	if(zeros<=ones)
	{
		printZeros(arr, n);
	}
	else
	{
		printOnes(arr, n);
	}
}

void minFlips_efficient(int arr[], int n)
{
	 for(int i=1;i<n;i++)
	 {
	 	if(arr[i-1]!=arr[i])
	 	{
	 		if(arr[i]!=arr[0])
	 		{
	 			cout<<"From "<<i<<" to ";
	 		}
	 		else
	 		{
	 			cout<<i-1<<endl;
	 		}
	 	}
	 }
	 if(arr[n-1]!=arr[0])
	 {
	 	cout<<n-1<<endl;
	 }
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	minFlips_efficient(arr, n);
}
