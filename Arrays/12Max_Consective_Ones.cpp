//Given a binary array of size n, find out the maximum consective ones in the array
#include<iostream>
using namespace std;
int printMaxOnes(int arr[], int n)
{
	int res = 0;
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i] == 0)
		{
			count = 0;
		}
		else
		{
			count++;
			res = max(res, count);
		}	
	}
	//res = max(res, count);
	return res;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<printMaxOnes(arr, n)<<endl;
	return 0;
}
