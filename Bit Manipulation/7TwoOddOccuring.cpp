//Given an array of size n, it has two elements that has their count as odd. Find them
#include<iostream>
using namespace std;
void twoOddOccuring(int arr[], int n)
{
	int temp = 0;
	for(int i=0;i<n;i++)
		temp = temp^arr[i];
	int res1=0, res2=0;
	int Sn = temp & (~(temp-1));
	for(int i=0;i<n;i++)
	{
		if(arr[i] & Sn)
			res1 = res1^arr[i];
		else
			res2 = res2^arr[i];
	}	
	cout<<res1<<" "<<res2<<endl;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	twoOddOccuring(arr, n);
	return 0;
}

