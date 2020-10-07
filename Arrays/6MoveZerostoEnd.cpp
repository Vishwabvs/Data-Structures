//Given an array of size n, move all the zeros present in the array to end
#include<iostream>
using namespace std;
void moveZeros(int *arr, int n)
{
	int count = 0;
	int next = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			//next = i;
			count++;
		}
		else 
		{
			arr[next++] = arr[i];
		}
	}
	cout<<next<<" "<<count<<endl;
	for(int i=0;i<count;i++)
		arr[next++] = 0;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	moveZeros(arr, n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
