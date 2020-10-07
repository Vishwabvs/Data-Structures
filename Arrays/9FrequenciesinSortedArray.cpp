#include<iostream>
using namespace std;
void countFreq(int arr[], int n)
{
	int freq = 1;
	int i;
	for(i=1;i<n;i++)
	{
		while(i<n && arr[i]==arr[i-1])
		{
			freq++;
			i++;
		}
		cout<<arr[i-1]<<" "<<freq<<endl;
		freq = 1;
	}
	cout<<i<<endl;
}
int main()
{
	int n, x;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	countFreq(arr, n);
	return 0;
}
