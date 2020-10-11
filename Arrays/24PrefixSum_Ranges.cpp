//Given n ranges, find the maximum appearing element in these ranges
#include<iostream>
using namespace std;
int findmax(int L[], int R[], int n)
{
	int res = L[0];
	for(int i=0;i<n;i++)
	{
		res = max(max(res, L[i]), R[i]);
	}
	return res;
}
int maxRanges(int L[], int R[], int n)
{
	int maximum = findmax(L, R, n);
	//cout<<maximum<<endl;
	int arr[maximum+1] = {0};
	for(int i=0;i<n;i++)
	{
		//cout<<L[i]<<" "<<R[i]<<endl;
		for(int j=L[i];j<=R[i];j++)
		{
			arr[j]++;
		}
	}
	int temp = arr[1], res;
	for(int i=0;i<=maximum;i++)
	{
		//cout<<arr[i]<<" ";
		if(temp<arr[i])
		{
			res = i;
			temp  = arr[i];
		}
	}
	//cout<<endl;	
	return res;
}
int maxRanges_efficient(int L[], int R[], int n)
{
	int maximum = findmax(L, R, n);
	//cout<<maximum<<endl;
	int arr[maximum+1] = {0};
	for(int i=0;i<n;i++)
	{
		arr[L[i]]++;
		arr[R[i]+1]--;
	}
	int temp = arr[0], res = 0;
	for(int i=1;i<=maximum;i++)
	{
		arr[i] += arr[i-1];
		if(temp<arr[i])
		{
			temp = arr[i];
			res = i;
		}
	}
	return res;
}
int main()
{
	int n;	
	cin>>n;
	int L[n];
	for(int i=0;i<n;i++)
		cin>>L[i];
	int R[n];
	for(int i=0;i<n;i++)
		cin>>R[i];
	cout<<maxRanges_efficient(L, R, n)<<endl;
}
