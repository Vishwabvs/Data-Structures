//Given data of stocks before hand, predict the max profit that can be obtained
//https://www.geeksforgeeks.org/stock-buy-sell/
#include<iostream>
using namespace std;
int getProfit(int arr[], int n)
{
	int max_sum=0, curr_sum=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
		{
			curr_sum += arr[i]-arr[i-1];
			continue;
		}
		else
		{
			max_sum +=curr_sum;
			curr_sum = 0;
		}
	}
	max_sum += curr_sum;
	return max_sum;
}
int getProfit_simple(int arr[], int n)
{
	int profit=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
			profit+=arr[i]-arr[i-1];
	}
	return profit;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<getProfit_simple(arr, n)<<endl;
	return 0;
}
